////#include <iostream>
////#include <queue>
////using namespace std;
////
////
////// 备忘录数组，记录已经访问过的位置
////bool visited[100][100];
////int dir[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // 方向数组
////
////bool DFS_find_exit_path(int x, int y, char v[100][100], int N, int M,int HP) {
////    // 终止条件
////    if (x == N && y == M && HP > 0) {
////        return true; // 已经到达目标点
////    }
////    // 递归搜索
////    for (int i = 0; i < 4; i++) {
////        int nx = x + dir[i][0];
////        int ny = y + dir[i][1];
////        if (nx >= 0 && nx < N && ny >= 0 && ny < M && v[nx][ny] != 'W'&&!visited[nx][ny]) {
////            if (v[nx][ny] = 'X') {
////                HP--;
////            }
////                visited[nx][ny] = true;
////                DFS_find_exit_path(nx, ny, v, N, M,HP);
////                // 恢复HP的值
////                if (v[nx][ny] == 'X') {
////                    HP++;
////                }
////            }
////         
////        }
////  
////
////    return false; // 所有方向都尝试过，没有找到路径
////}
////
////int main() {
////    int N, M, K;
////    char v[100][100];
////    int HP = 3;
////    cin >> K >> M >> N;
////    for (int i = 1; i <= K; i++) {
////        for (int t = 1; t <= M; t++) {
////            for (int j = 1; j <= N; j++) {
////                cin >> v[t][j];
////            }
////        }
////        if (DFS_find_exit_path(1, 1, v, N, M,HP)) {
////            printf("YES\n");
////        }
////        else {
////            printf("NO\n");
////        }
////    }
////
////    return 0;
////}
//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//// 定义地牢中的地块类型
//const char WALL = 'W';
//const char GROUND = 'G';
//const char TRAP = 'X';
//
//// 定义地牢的规模
//int M, N;
//
//// 定义地牢的结构
//vector<vector<char>> dungeon;
//
//// 定义坐标结构体
//struct Point {
//    int x, y, hp;
//    Point(int _x, int _y, int _hp) : x(_x), y(_y), hp(_hp) {}
//};
//
//// BFS 搜索函数
//bool bfs(Point start) {
//    // 定义方向数组
//    int dx[] = { -1, 1, 0, 0 };
//    int dy[] = { 0, 0, -1, 1 };
//
//    // 定义队列
//    queue<Point> q;
//    q.push(start);
//
//    // 记录已访问过的地块
//    vector<vector<bool>> visited(M, vector<bool>(N, false));
//    visited[start.x][start.y] = true;
//
//    // 开始 BFS
//    while (!q.empty()) {
//        Point cur = q.front();
//        q.pop();
//
//        // 如果当前位置是终点，返回 true
//        if (cur.x == M - 1 && cur.y == N - 1)
//            return true;
//
//        // 遍历当前位置的四个方向
//        for (int i = 0; i < 4; ++i) {
//            int nx = cur.x + dx[i];
//            int ny = cur.y + dy[i];
//
//            // 判断下一个位置是否合法
//            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && (dungeon[nx][ny] == GROUND || dungeon[nx][ny] == TRAP)) {
//                // 计算下一个位置的血量
//                int nhp = cur.hp;
//                if (dungeon[nx][ny] == TRAP) {
//                    nhp--;
//                    if (nhp <= 0)
//                        continue;
//                }
//
//                // 将下一个位置加入队列，并标记为已访问
//                q.push(Point(nx, ny, nhp));
//                visited[nx][ny] = true;
//            }
//        }
//    }
//
//    // 如果 BFS 结束时还未到达终点，返回 false
//    return false;
//}
//
//int main() {
//    int K;
//    cin >> K >> M >> N;
//
//    // 逐个地牢进行判断
//    for (int k = 0; k < K; ++k) {
//        dungeon.clear();
//        dungeon.resize(M, vector<char>(N));
//
//        // 读入地牢信息
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                cin >> dungeon[i][j];
//            }
//        }
//
//        // 判断是否能够夺宝成功
//        if (bfs(Point(0, 0, 3))) { // 初始血量为 3
//            cout << "YES" << endl;
//        }
//        else {
//            cout << "NO" << endl;
//        }
//    }
//
//    return 0;
//}
