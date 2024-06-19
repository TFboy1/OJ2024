//#include<bits/stdc++.h>
//#include <climits>
//#include <cstdlib>
//#include <utility>
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
//char solve()
//{
//    // 寻找最近的豆子作为目标
//    pair<int, int> target;
//    int minDist = 101;
//
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= 40; ++j) {
//            if (a[i][j] == 2) {
//                int dist = abs(person_x - i) + abs(person_y - j); // 曼哈顿距离
//                if (dist < minDist) {
//                    minDist = dist;
//                    target = { i, j };
//                }
//            }
//        }
//    }
//
//    // 根据目标位置和当前位置的关系选择最佳移动方向
//    int tx = target.first;
//    int ty = target.second;
//
//    // 如果目标位置和当前位置相同，返回停留
//    if (tx == person_x && ty == person_y) return 'S';
//
//    // 如果有鬼在附近，并且距离吃豆人更近，优先选择远离鬼的方向移动
//    if (a[person_x - 1][person_y] == 8 && abs(person_x - 1 - tx) < abs(person_x - tx) && a[person_x - 1][person_y] != 4) return 'U';
//    if (a[person_x + 1][person_y] == 8 && abs(person_x + 1 - tx) < abs(person_x - tx) && a[person_x + 1][person_y] != 4) return 'D';
//    if (a[person_x][person_y - 1] == 8 && abs(person_y - 1 - ty) < abs(person_y - ty) && a[person_x][person_y - 1] != 4) return 'L';
//    if (a[person_x][person_y + 1] == 8 && abs(person_y + 1 - ty) < abs(person_y - ty) && a[person_x][person_y + 1] != 4) return 'R';
//
//    // 否则根据目标位置和当前位置的关系选择最佳移动方向，确保不会走进墙壁
//    if (tx < person_x && a[person_x - 1][person_y] != 4 && (a[person_x - 1][person_y] != 8 || a[person_x - 1][person_y] == 8 && a[person_x - 2][person_y] != 4)) return 'U';
//    if (tx > person_x && a[person_x + 1][person_y] != 4 && (a[person_x + 1][person_y] != 8 || a[person_x + 1][person_y] == 8 && a[person_x + 2][person_y] != 4)) return 'D';
//    if (ty < person_y && a[person_x][person_y - 1] != 4 && (a[person_x][person_y - 1] != 8 || a[person_x][person_y - 1] == 8 && a[person_x][person_y - 2] != 4)) return 'L';
//    if (ty > person_y && a[person_x][person_y + 1] != 4 && (a[person_x][person_y + 1] != 8 || a[person_x][person_y + 1] == 8 && a[person_x][person_y + 2] != 4)) return 'R';
//
//    // 如果无法移动到目标位置，返回停留
//    return 'S';
//}
//
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
