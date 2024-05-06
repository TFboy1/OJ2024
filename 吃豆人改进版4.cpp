//#include<bits/stdc++.h>
//#include <climits>
//#include <cstdlib>
//#include <utility>
//#include <vector>
//#include <queue>
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
//// 定义豆子的坐标结构体
//struct Bean {
//    int x, y;
//};
//
//// 检查鬼是否在可怕范围内
//bool is_ghost_nearby(int person_x, int person_y, int ghost_x, int ghost_y) {
//    // 计算鬼和吃豆人的曼哈顿距离
//    int distance = abs(person_x - ghost_x) + abs(person_y - ghost_y);
//    // 如果距离小于等于2，则鬼在可怕范围内
//    return distance <= 2;
//}
//
//char solve()
//{
//    // 当前吃豆人的坐标
//    int curr_x = person_x;
//    int curr_y = person_y;
//
//    // 遍历地图，查找鬼的位置
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= 40; ++j) {
//            // 如果当前位置是鬼，并且在可怕范围内
//            if (a[i][j] == 8 && is_ghost_nearby(curr_x, curr_y, i, j)) {
//                // 尝试躲避鬼
//                // 检查上方是否安全，是则移动上方
//                if (a[curr_x - 1][curr_y] != 8 && a[curr_x - 1][curr_y] != 4) {
//                    return 'U';
//                }
//                // 检查下方是否安全，是则移动下方
//                else if (a[curr_x + 1][curr_y] != 8 && a[curr_x + 1][curr_y] != 4) {
//                    return 'D';
//                }
//                // 检查左方是否安全，是则移动左方
//                else if (a[curr_x][curr_y - 1] != 8 && a[curr_x][curr_y - 1] != 4) {
//                    return 'L';
//                }
//                // 检查右方是否安全，是则移动右方
//                else if (a[curr_x][curr_y + 1] != 8 && a[curr_x][curr_y + 1] != 4) {
//                    return 'R';
//                }
//                // 如果四个方向都有鬼或墙，随机选择一个方向移动
//                else {
//                    int op = rand() % 4;
//                    if (op == 0) {
//                        return 'U';
//                    }
//                    else if (op == 1) {
//                        return 'D';
//                    }
//                    else if (op == 2) {
//                        return 'L';
//                    }
//                    else {
//                        return 'R';
//                    }
//                }
//            }
//        }
//    }
//
//    // 创建一个二维数组来记录豆子的状态，初始化为 false
//    bool visited[20][40] = { false };
//
//    // 创建一个队列来存储待访问的豆子
//    std::queue<Bean> beansQueue;
//
//    // 遍历地图，将所有豆子加入队列
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= 40; ++j) {
//            if (a[i][j] == 2) {
//                beansQueue.push({ i, j });
//            }
//        }
//    }
//
//    // 如果队列不为空，说明还有豆子未被访问
//    if (!beansQueue.empty()) {
//        // 创建一个数组来记录吃豆人到各个豆子的最短距离
//        std::vector<std::vector<int>> distance(20, std::vector<int>(40, -1));
//
//        // 标记当前位置已经访问过
//        visited[curr_x][curr_y] = true;
//        distance[curr_x][curr_y] = 0;
//
//        // 创建一个变量来记录最近的豆子的距离和坐标
//        int minDistance = INT_MAX;
//        int minBean_x = -1;
//        int minBean_y = -1;
//
//        // 创建一个变量来记录下一步的移动方向
//        char nextMove = '\0';
//
//        // 创建一个变量来标记是否找到了可达的豆子
//        bool foundBean = false;
//
//        // 使用广度优先搜索遍历地图，找到到达所有豆子的最短路径
//        while (!beansQueue.empty()) {
//            // 出队一个豆子
//            Bean bean = beansQueue.front();
//            beansQueue.pop();
//
//            // 获取当前豆子的坐标
//            int bean_x = bean.x;
//            int bean_y = bean.y;
//
//            // 计算当前豆子到吃豆人的距离
//            int dist = distance[curr_x][curr_y] + abs(curr_x - bean_x) + abs(curr_y - bean_y);
//
//            // 更新到当前豆子的最短距离
//            if (dist < minDistance) {
//                minDistance = dist;
//                minBean_x = bean_x;
//                minBean_y = bean_y;
//            }
//
//            // 将当前豆子标记为已访问
//            visited[bean_x][bean_y] = true;
//
//            // 将当前豆子的周围豆子加入队列
//            if (bean_x > 1 && !visited[bean_x - 1][bean_y]) {
//                beansQueue.push({ bean_x - 1, bean_y });
//                visited[bean_x - 1][bean_y] = true;
//                distance[bean_x - 1][bean_y] = dist + 1;
//            }
//            if (bean_x < 20 && !visited[bean_x + 1][bean_y]) {
//                beansQueue.push({ bean_x + 1, bean_y });
//                visited[bean_x + 1][bean_y] = true;
//                distance[bean_x + 1][bean_y] = dist + 1;
//            }
//            if (bean_y > 1 && !visited[bean_x][bean_y - 1]) {
//                beansQueue.push({ bean_x, bean_y - 1 });
//                visited[bean_x][bean_y - 1] = true;
//                distance[bean_x][bean_y - 1] = dist + 1;
//            }
//            if (bean_y < 40 && !visited[bean_x][bean_y + 1]) {
//                beansQueue.push({ bean_x, bean_y + 1 });
//                visited[bean_x][bean_y + 1] = true;
//                distance[bean_x][bean_y + 1] = dist + 1;
//            }
//        }
//
//        // 如果找到了最近的豆子，计算最优的移动方向
//        if (minBean_x != -1 && minBean_y != -1) {
//            // 根据最近豆子的坐标和当前吃豆人的坐标计算移动方向
//            if (minBean_x < curr_x) {
//                nextMove = 'U';
//            }
//            else if (minBean_x > curr_x) {
//                nextMove = 'D';
//            }
//            else if (minBean_y < curr_y) {
//                nextMove = 'L';
//            }
//            else if (minBean_y > curr_y) {
//                nextMove = 'R';
//            }
//        }
//
//        // 如果找到了最优的移动方向，则返回该方向
//        if (nextMove != '\0') {
//            return nextMove;
//        }
//    }
//
//    // 如果没有豆子可供吃，按照原有的策略移动
//
//    // 检查上方是否有豆子，是则移动上方
//    if (a[curr_x - 1][curr_y] == 2) {
//        return 'U';
//    }
//    // 检查下方是否有豆子，是则移动下方
//    else if (a[curr_x + 1][curr_y] == 2) {
//        return 'D';
//    }
//    // 检查左方是否有豆子，是则移动左方
//    else if (a[curr_x][curr_y - 1] == 2) {
//        return 'L';
//    }
//    // 检查右方是否有豆子，是则移动右方
//    else if (a[curr_x][curr_y + 1] == 2) {
//        return 'R';
//    }
//    // 如果四个方向都没有豆子，则随机选择一个方向移动
//    else {
//        int op = rand() % 4;
//        if (op == 0) {
//            return 'U';
//        }
//        else if (op == 1) {
//            return 'D';
//        }
//        else if (op == 2) {
//            return 'L';
//        }
//        else {
//            return 'R';
//        }
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
