#include<bits/stdc++.h>
#include <queue>
#define endl '\n'
#define MAX_X 60
#define MAX_Y 60
#define int long long
using namespace std;

const int N = 50;
int a[N][N];

const int szx = 20;
const int szy = 40;

string s;

void get_map(string mp) {

    //cin >> mp;
    for (int i = 1; i <= szx; i++)
        for (int j = 1; j <= szy; j++) {
            int pos = (i - 1) * szy + j;
            pos--;
            int st = mp[pos] - '0';
            a[i][j] = st;
        }
    return;
}

pair<int, int> get_ghost_pos1(string p) {
    int x1 = (p[0] - '0') * 10 + p[1] - '0';
    int y1 = (p[2] - '0') * 10 + p[3] - '0';
    return { x1 ,y1 };
}

pair<pair<int, int>, pair<int, int>> get_ghost_pos2(string p) {
    int x1 = (p[0] - '0') * 10 + p[1] - '0';
    int y1 = (p[2] - '0') * 10 + p[3] - '0';
    int x2 = (p[4] - '0') * 10 + p[5] - '0';
    int y2 = (p[6] - '0') * 10 + p[7] - '0';
    return { {x2, y2},{x1 ,y1} };
}

pair<int, int> preghost1;

pair< pair<int, int>, pair<int, int> > preghost2;

int person_x = 0;
int person_y = 0;

void init_mp() {

    get_map(s);
    int cnt = 0;
    for (int i = 1; i <= szx; i++) {
        for (int j = 1; j <= szy; j++) {
            if (a[i][j] == 5) a[i][j] = 8;
            if (a[i][j] == 6) a[i][j] = 10;
            if (a[i][j] & 1) {
                person_x = i;   // 
                person_y = j;   // 
            }
            if ((a[i][j] >> 3) & 1) {

                if (cnt == 0) {
                    preghost1.first = i;
                    preghost1.second = j;
                    cnt++;
                }
                else {
                    preghost2.first = preghost1;
                    preghost2.second.first = i;
                    preghost2.second.second = j;
                }

            }
        }
    }

}

void react_ghost() {

    if (s.size() == 8) {

        auto ghost = get_ghost_pos2(s);

        int x1 = preghost2.first.first;
        int y1 = preghost2.first.second;

        int x2 = preghost2.second.first;
        int y2 = preghost2.second.second;

        a[x1][y1] ^= (1ll << 3);
        a[x2][y2] ^= (1ll << 3);

        a[ghost.first.first][ghost.first.second] ^= (1ll << 3);
        a[ghost.second.first][ghost.second.second] ^= (1ll << 3);

        preghost2 = ghost;

    }
    else if (s.size() == 4) {

        int x = preghost1.first;
        int y = preghost1.second;

        a[x][y] ^= (1ll << 3);

        auto ghost = get_ghost_pos1(s);

        a[ghost.first][ghost.second] ^= (1ll << 3);

        preghost1 = ghost;
    }

}


int seed = 135;
int nowv = 0;
const int mod = 1e9 + 7;

int my_rand(int l, int r) {

    nowv += seed;
    nowv %= mod;
    nowv = (nowv * nowv) % mod;

    nowv += (5 * seed) / 3;
    nowv %= mod;

    return (nowv % (r - l + 1) + l);
}


void D() {
    a[person_x][person_y] ^= 1;
    person_x++;
    a[person_x][person_y] ^= 1;
    cout << "D" << endl;
}

void U() {
    a[person_x][person_y] ^= 1;
    person_x--;
    a[person_x][person_y] ^= 1;
    cout << "U" << endl;
}

void L() {
    a[person_x][person_y] ^= 1;
    person_y--;
    a[person_x][person_y] ^= 1;
    cout << "L" << endl;
}

void R() {
    a[person_x][person_y] ^= 1;
    person_y++;
    a[person_x][person_y] ^= 1;
    cout << "R" << endl;
}


/*
    你的策略
    如果你需要写递归，可以在solve函数之前添加你的递归函数并在solve函数中调用。
*/

struct Point {
    int x, y;
};

// 定义方向常量
const int dx[] = { -1, 1, 0, 0 }; // 上下左右
const int dy[] = { 0, 0, -1, 1 };
struct State {
    int x, y, steps;
    State(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps) {}
};
char bfs(int target_x, int target_y) {
        queue<State> q;
     bool visited[50][50];
     memset(visited, false, sizeof(visited));
 
     // 初始化起始状态
     q.push(State(person_x, person_y, 0));
 
     // 开始 BFS
     while (!q.empty()) {
         State cur = q.front();
         q.pop();
 
         // 判断是否找到目标状态（假设目标状态是吃到豆子的位置）
         if (a[cur.x][cur.y] == 2) {
             if (cur.x < person_x) return 'U';
             if (cur.x > person_x) return 'D';
             if (cur.y < person_y) return 'L';
             if (cur.y > person_y) return 'R';
         }
 
         // 扩展当前状态的所有可能的下一步状态
         vector<State> next_states;
         for (int i = 0; i < 4; ++i) {
             int nx = cur.x + dx[i];
             int ny = cur.y + dy[i];
             // 判断是否越界或者是墙，如果是则继续下一个方向
             if (nx < 0 || nx >= szx || ny < 0 || ny >= szy || a[nx][ny] == 4 || a[nx][ny] == 8 || a[nx][ny] == 10) continue;
 
             // 将新状态加入下一步状态列表
             next_states.push_back(State(nx, ny, cur.steps + 1));
         }
 
         // 根据新状态的位置，选择距离鬼比较远且有豆子的方向
         sort(next_states.begin(), next_states.end(), [&](const State& a, const State& b) {
             if (a.steps != b.steps)
                 return a.steps < b.steps; // 优先移动步数少的状态
             else {
                 // 当步数相同时，选择距离鬼比较远且有豆子的方向
                 if (a.x < person_x && b.x < person_x) {
                     return a.y < b.y; // 如果都在上方，选择 y 更小的方向
                 }
                 else if (a.x > person_x && b.x > person_x) {
                     return a.y < b.y; // 如果都在下方，选择 y 更小的方向
                 }
                 else if (a.y < person_y && b.y < person_y) {
                     return a.x < b.x; // 如果都在左方，选择 x 更小的方向
                 }
                 else if (a.y > person_y && b.y > person_y) {
                     return a.x < b.x; // 如果都在右方，选择 x 更小的方向
                 }
                 else {
                     // 否则，选择距离鬼比较远且有豆子的方向
                     return a.steps > b.steps;
                 }
             }
             });
 
         // 将下一步状态加入队列
         for (const auto& state : next_states) {
             q.push(state);
         }
     }
 
     // 如果找不到目标状态，则返回一个默认值
     return 'R';
}

char solve() {
    int up = a[person_x - 1][person_y];
    int down = a[person_x + 1][person_y];
    int left = a[person_x][person_y - 1];
    int right = a[person_x][person_y + 1];

    // 如果没有豆子相邻但有鬼相邻，则选择远离鬼的方向
    if (up == 8||up==10)
        return 'D';
    else if (down == 8||down==10)
        return 'U';
    else if (left == 8||left==10)
        return 'R';
    else if (right == 8||right==10)
        return 'L';

    // 如果既没有豆子相邻也没有鬼相邻，选择离得最近的豆子方向
    // 调用BFS算法找到最近的豆子方向
    return bfs(person_x, person_y);
}


signed main() {

    while (cin >> s) {


        if (s.size() >= 40) {
            init_mp();

        }
        else {
            react_ghost();
        }

        char x = solve();

        if (x == 'U') {
            U();
        }
        else if (x == 'L') {
            L();
        }
        else if (x == 'R') {
            R();
        }
        else D();

        if ((a[person_x][person_y] >> 1) & 1) {
            a[person_x][person_y] ^= (1ll << 1);
        }

    }

    return 0;
}
