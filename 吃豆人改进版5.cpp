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
    ��Ĳ���
    �������Ҫд�ݹ飬������solve����֮ǰ�����ĵݹ麯������solve�����е��á�
*/

struct Point {
    int x, y;
};

// ���巽����
const int dx[] = { -1, 1, 0, 0 }; // ��������
const int dy[] = { 0, 0, -1, 1 };
struct State {
    int x, y, steps;
    State(int _x, int _y, int _steps) : x(_x), y(_y), steps(_steps) {}
};
char bfs(int target_x, int target_y) {
        queue<State> q;
     bool visited[50][50];
     memset(visited, false, sizeof(visited));
 
     // ��ʼ����ʼ״̬
     q.push(State(person_x, person_y, 0));
 
     // ��ʼ BFS
     while (!q.empty()) {
         State cur = q.front();
         q.pop();
 
         // �ж��Ƿ��ҵ�Ŀ��״̬������Ŀ��״̬�ǳԵ����ӵ�λ�ã�
         if (a[cur.x][cur.y] == 2) {
             if (cur.x < person_x) return 'U';
             if (cur.x > person_x) return 'D';
             if (cur.y < person_y) return 'L';
             if (cur.y > person_y) return 'R';
         }
 
         // ��չ��ǰ״̬�����п��ܵ���һ��״̬
         vector<State> next_states;
         for (int i = 0; i < 4; ++i) {
             int nx = cur.x + dx[i];
             int ny = cur.y + dy[i];
             // �ж��Ƿ�Խ�������ǽ��������������һ������
             if (nx < 0 || nx >= szx || ny < 0 || ny >= szy || a[nx][ny] == 4 || a[nx][ny] == 8 || a[nx][ny] == 10) continue;
 
             // ����״̬������һ��״̬�б�
             next_states.push_back(State(nx, ny, cur.steps + 1));
         }
 
         // ������״̬��λ�ã�ѡ������Ƚ�Զ���ж��ӵķ���
         sort(next_states.begin(), next_states.end(), [&](const State& a, const State& b) {
             if (a.steps != b.steps)
                 return a.steps < b.steps; // �����ƶ������ٵ�״̬
             else {
                 // ��������ͬʱ��ѡ������Ƚ�Զ���ж��ӵķ���
                 if (a.x < person_x && b.x < person_x) {
                     return a.y < b.y; // ��������Ϸ���ѡ�� y ��С�ķ���
                 }
                 else if (a.x > person_x && b.x > person_x) {
                     return a.y < b.y; // ��������·���ѡ�� y ��С�ķ���
                 }
                 else if (a.y < person_y && b.y < person_y) {
                     return a.x < b.x; // ��������󷽣�ѡ�� x ��С�ķ���
                 }
                 else if (a.y > person_y && b.y > person_y) {
                     return a.x < b.x; // ��������ҷ���ѡ�� x ��С�ķ���
                 }
                 else {
                     // ����ѡ������Ƚ�Զ���ж��ӵķ���
                     return a.steps > b.steps;
                 }
             }
             });
 
         // ����һ��״̬�������
         for (const auto& state : next_states) {
             q.push(state);
         }
     }
 
     // ����Ҳ���Ŀ��״̬���򷵻�һ��Ĭ��ֵ
     return 'R';
}

char solve() {
    int up = a[person_x - 1][person_y];
    int down = a[person_x + 1][person_y];
    int left = a[person_x][person_y - 1];
    int right = a[person_x][person_y + 1];

    // ���û�ж������ڵ��й����ڣ���ѡ��Զ���ķ���
    if (up == 8||up==10)
        return 'D';
    else if (down == 8||down==10)
        return 'U';
    else if (left == 8||left==10)
        return 'R';
    else if (right == 8||right==10)
        return 'L';

    // �����û�ж�������Ҳû�й����ڣ�ѡ���������Ķ��ӷ���
    // ����BFS�㷨�ҵ�����Ķ��ӷ���
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
