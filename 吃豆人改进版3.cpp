//#include<bits/stdc++.h>
//#include <climits>
//#include <cstdlib>
//#include <utility>
//#include<queue>
//
//#define endl '\n'
//#define int long long
//using namespace std;
//
//const int N = 50;
//int a[N][N];
//
//const int szx = 20;
//const int szy = 40;
//
//string s;
//
//void get_map(string mp) {
//
//    //cin >> mp;
//    for (int i = 1; i <= szx; i++)
//        for (int j = 1; j <= szy; j++) {
//            int pos = (i - 1) * szy + j;
//            pos--;
//            int st = mp[pos] - '0';
//            a[i][j] = st;
//        }
//    return;
//}
//
//pair<int, int> get_ghost_pos1(string p) {
//    int x1 = (p[0] - '0') * 10 + p[1] - '0';
//    int y1 = (p[2] - '0') * 10 + p[3] - '0';
//    return { x1 ,y1 };
//}
//
//pair<pair<int, int>, pair<int, int>> get_ghost_pos2(string p) {
//    int x1 = (p[0] - '0') * 10 + p[1] - '0';
//    int y1 = (p[2] - '0') * 10 + p[3] - '0';
//    int x2 = (p[4] - '0') * 10 + p[5] - '0';
//    int y2 = (p[6] - '0') * 10 + p[7] - '0';
//    return { {x2, y2},{x1 ,y1} };
//}
//
//pair<int, int> preghost1;
//
//pair< pair<int, int>, pair<int, int> > preghost2;
//
//int person_x = 0;
//int person_y = 0;
//
//void init_mp() {
//
//    get_map(s);
//    int cnt = 0;
//    for (int i = 1; i <= szx; i++) {
//        for (int j = 1; j <= szy; j++) {
//            if (a[i][j] == 5) a[i][j] = 8;
//            if (a[i][j] == 6) a[i][j] = 10;
//            if (a[i][j] & 1) {
//                person_x = i;   // 
//                person_y = j;   // 
//            }
//            if ((a[i][j] >> 3) & 1) {
//
//                if (cnt == 0) {
//                    preghost1.first = i;
//                    preghost1.second = j;
//                    cnt++;
//                }
//                else {
//                    preghost2.first = preghost1;
//                    preghost2.second.first = i;
//                    preghost2.second.second = j;
//                }
//
//            }
//        }
//    }
//
//}
//
//void react_ghost() {
//
//    if (s.size() == 8) {
//
//        auto ghost = get_ghost_pos2(s);
//
//        int x1 = preghost2.first.first;
//        int y1 = preghost2.first.second;
//
//        int x2 = preghost2.second.first;
//        int y2 = preghost2.second.second;
//
//        a[x1][y1] ^= (1ll << 3);
//        a[x2][y2] ^= (1ll << 3);
//
//        a[ghost.first.first][ghost.first.second] ^= (1ll << 3);
//        a[ghost.second.first][ghost.second.second] ^= (1ll << 3);
//
//        preghost2 = ghost;
//
//    }
//    else if (s.size() == 4) {
//
//        int x = preghost1.first;
//        int y = preghost1.second;
//
//        a[x][y] ^= (1ll << 3);
//
//        auto ghost = get_ghost_pos1(s);
//
//        a[ghost.first][ghost.second] ^= (1ll << 3);
//
//        preghost1 = ghost;
//    }
//
//}
//
//
//int seed = 135;
//int nowv = 0;
//const int mod = 1e9 + 7;
//
//int my_rand(int l, int r) {
//
//    nowv += seed;
//    nowv %= mod;
//    nowv = (nowv * nowv) % mod;
//
//    nowv += (5 * seed) / 3;
//    nowv %= mod;
//
//    return (nowv % (r - l + 1) + l);
//}
//
//
//void D() {
//    a[person_x][person_y] ^= 1;
//    person_x++;
//    a[person_x][person_y] ^= 1;
//    cout << "D" << endl;
//}
//
//void U() {
//    a[person_x][person_y] ^= 1;
//    person_x--;
//    a[person_x][person_y] ^= 1;
//    cout << "U" << endl;
//}
//
//void L() {
//    a[person_x][person_y] ^= 1;
//    person_y--;
//    a[person_x][person_y] ^= 1;
//    cout << "L" << endl;
//}
//
//void R() {
//    a[person_x][person_y] ^= 1;
//    person_y++;
//    a[person_x][person_y] ^= 1;
//    cout << "R" << endl;
//}
//
//
///*
//    你的策略
//    如果你需要写递归，可以在solve函数之前添加你的递归函数并在solve函数中调用。
//*/
//
//
//// 检查给定坐标是否有效且可访问
//bool isValid(int x, int y, int a[21][41]) {
//    return x >= 1 && x <= 20 && y >= 1 && y <= 40 && a[x][y] != 4;
//}
//
//// BFS搜索最近的豆子，同时考虑鬼魂的当前位置
//std::pair<int, int> findNearestBean(int person_x, int person_y, int a[21][41], std::pair<int, int> ghost) {
//    std::queue<std::pair<int, int>> q;
//    bool visited[21][41] = { false };
//    int dx[4] = { -1, 1, 0, 0 }; // 上、下、左、右
//    int dy[4] = { 0, 0, -1, 1 };
//
//    q.push({ person_x, person_y });
//    visited[person_x][person_y] = true;
//
//    while (!q.empty()) {
//        auto curr = q.front(); q.pop();
//        int x = curr.first, y = curr.second;
//
//        // 如果找到豆子，返回位置
//        if (a[x][y] == 2) return curr;
//
//        for (int i = 0; i < 4; ++i) {
//            int nx = x + dx[i], ny = y + dy[i];
//            // 避免撞到鬼魂
//            if (nx == ghost.first && ny == ghost.second) continue;
//            if (isValid(nx, ny, a) && !visited[nx][ny]) {
//                visited[nx][ny] = true;
//                q.push({ nx, ny });
//            }
//        }
//    }
//
//    // 如果没有找到豆子，返回{-1, -1}
//    return { -1, -1 };
//}
//char solve() {
//    // 假设只有一个鬼魂
//    std::pair<int, int> ghost = preghost1;
//
//    auto target = findNearestBean(person_x, person_y, a, ghost);
//
//    // 如果没有找到豆子，随机移动
//    if (target.first == -1 && target.second == -1) {
//        int op = my_rand(1, 4);
//        return op == 1 ? 'U' : op == 2 ? 'D' : op == 3 ? 'R' : 'L';
//    }
//
//    // 计算吃豆人应该移动的方向
//    int dx = target.first - person_x;
//    int dy = target.second - person_y;
//
//    if (abs(dx) > abs(dy)) {
//        return dx > 0 ? 'D' : 'U';
//    }
//    else {
//        return dy > 0 ? 'R': 'L';
//    }
//}
//
//signed main() {
//
//    while (cin >> s) {
//
//
//        if (s.size() >= 40) {
//            init_mp();
//
//        }
//        else {
//            react_ghost();
//        }
//
//        char x = solve();
//
//        if (x == 'U') {
//            U();
//        }
//        else if (x == 'L') {
//            L();
//        }
//        else if (x == 'R') {
//            R();
//        }
//        else D();
//
//        if ((a[person_x][person_y] >> 1) & 1) {
//            a[person_x][person_y] ^= (1ll << 1);
//        }
//
//    }
//
//    return 0;
//}
