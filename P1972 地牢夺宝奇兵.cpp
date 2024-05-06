//////#include <iostream>
//////#include <queue>
//////using namespace std;
//////
//////
//////// ����¼���飬��¼�Ѿ����ʹ���λ��
//////bool visited[100][100];
//////int dir[][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }; // ��������
//////
//////bool DFS_find_exit_path(int x, int y, char v[100][100], int N, int M,int HP) {
//////    // ��ֹ����
//////    if (x == N && y == M && HP > 0) {
//////        return true; // �Ѿ�����Ŀ���
//////    }
//////    // �ݹ�����
//////    for (int i = 0; i < 4; i++) {
//////        int nx = x + dir[i][0];
//////        int ny = y + dir[i][1];
//////        if (nx >= 0 && nx < N && ny >= 0 && ny < M && v[nx][ny] != 'W'&&!visited[nx][ny]) {
//////            if (v[nx][ny] = 'X') {
//////                HP--;
//////            }
//////                visited[nx][ny] = true;
//////                DFS_find_exit_path(nx, ny, v, N, M,HP);
//////                // �ָ�HP��ֵ
//////                if (v[nx][ny] == 'X') {
//////                    HP++;
//////                }
//////            }
//////         
//////        }
//////  
//////
//////    return false; // ���з��򶼳��Թ���û���ҵ�·��
//////}
//////
//////int main() {
//////    int N, M, K;
//////    char v[100][100];
//////    int HP = 3;
//////    cin >> K >> M >> N;
//////    for (int i = 1; i <= K; i++) {
//////        for (int t = 1; t <= M; t++) {
//////            for (int j = 1; j <= N; j++) {
//////                cin >> v[t][j];
//////            }
//////        }
//////        if (DFS_find_exit_path(1, 1, v, N, M,HP)) {
//////            printf("YES\n");
//////        }
//////        else {
//////            printf("NO\n");
//////        }
//////    }
//////
//////    return 0;
//////}
////#include <iostream>
////#include <vector>
////#include <queue>
////
////using namespace std;
////
////// ��������еĵؿ�����
////const char WALL = 'W';
////const char GROUND = 'G';
////const char TRAP = 'X';
////
////// ������εĹ�ģ
////int M, N;
////
////// ������εĽṹ
////vector<vector<char>> dungeon;
////
////// ��������ṹ��
////struct Point {
////    int x, y, hp;
////    Point(int _x, int _y, int _hp) : x(_x), y(_y), hp(_hp) {}
////};
////
////// BFS ��������
////bool bfs(Point start) {
////    // ���巽������
////    int dx[] = { -1, 1, 0, 0 };
////    int dy[] = { 0, 0, -1, 1 };
////
////    // �������
////    queue<Point> q;
////    q.push(start);
////
////    // ��¼�ѷ��ʹ��ĵؿ�
////    vector<vector<bool>> visited(M, vector<bool>(N, false));
////    visited[start.x][start.y] = true;
////
////    // ��ʼ BFS
////    while (!q.empty()) {
////        Point cur = q.front();
////        q.pop();
////
////        // �����ǰλ�����յ㣬���� true
////        if (cur.x == M - 1 && cur.y == N - 1)
////            return true;
////
////        // ������ǰλ�õ��ĸ�����
////        for (int i = 0; i < 4; ++i) {
////            int nx = cur.x + dx[i];
////            int ny = cur.y + dy[i];
////
////            // �ж���һ��λ���Ƿ�Ϸ�
////            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny] && (dungeon[nx][ny] == GROUND || dungeon[nx][ny] == TRAP)) {
////                // ������һ��λ�õ�Ѫ��
////                int nhp = cur.hp;
////                if (dungeon[nx][ny] == TRAP) {
////                    nhp--;
////                    if (nhp <= 0)
////                        continue;
////                }
////
////                // ����һ��λ�ü�����У������Ϊ�ѷ���
////                q.push(Point(nx, ny, nhp));
////                visited[nx][ny] = true;
////            }
////        }
////    }
////
////    // ��� BFS ����ʱ��δ�����յ㣬���� false
////    return false;
////}
////
////int main() {
////    int K;
////    cin >> K >> M >> N;
////
////    // ������ν����ж�
////    for (int k = 0; k < K; ++k) {
////        dungeon.clear();
////        dungeon.resize(M, vector<char>(N));
////
////        // ���������Ϣ
////        for (int i = 0; i < M; ++i) {
////            for (int j = 0; j < N; ++j) {
////                cin >> dungeon[i][j];
////            }
////        }
////
////        // �ж��Ƿ��ܹ��ᱦ�ɹ�
////        if (bfs(Point(0, 0, 3))) { // ��ʼѪ��Ϊ 3
////            cout << "YES" << endl;
////        }
////        else {
////            cout << "NO" << endl;
////        }
////    }
////
////    return 0;
////}
////
//#include <iostream>
//#include <stack>
//
//using namespace std;
//
//// ������εĽṹ��
//struct Dungeon {
//public:
//    int M, N;
//    char grid[50][50];
//    bool visited[50][50];
//};
//
//// ����ڵ�ṹ�壬���ڴ洢DFS�е�״̬��Ϣ
//struct Node {
//    int x, y, health;
//    Node(int _x, int _y, int _health) : x(_x), y(_y), health(_health) {}
//};
//
//// DFS���������������Ƿ���ڿ���·��
//bool dfs( Dungeon& dungeon) {
//    int M = dungeon.M, N = dungeon.N;
//    stack<Node> stk;
//    stk.push(Node(0, 0, 3));
//
//    while (!stk.empty()) {
//        Node node = stk.top();
//        stk.pop();
//        int x = node.x, y = node.y, health = node.health;
//
//        // �����ǰλ��Ϊ�յ㣬�򷵻�true
//        if (x == M - 1 && y == N - 1) {
//            return true;
//        }
//
//        // �����ǰλ��Խ�硢Ϊ����ͨ�е�����ؿ顢Ѫ������0���»����Ѿ����ʹ�����������ǰ�ڵ�
//        if (x < 0 || x >= M || y < 0 || y >= N || dungeon.grid[x][y] == 'W' || health <= 0 || dungeon.visited[x][y]) {
//            continue;
//        }
//
//        // ��ǵ�ǰ�ڵ��Ѿ����ʹ�
//        dungeon.visited[x][y] = true;
//
//        // �����ǰλ��Ϊ��ͨ�е�����ؿ飬�����һ��Ѫ��
//        if (dungeon.grid[x][y] == 'X') {
//            health--;
//        }
//
//        // �����������ĸ���������������������������Ľڵ���ջ
//        stk.push(Node(x - 1, y, health));
//        stk.push(Node(x + 1, y, health));
//        stk.push(Node(x, y - 1, health));
//        stk.push(Node(x, y + 1, health));
//    }
//
//    // ���ջΪ�գ���δ�ҵ��յ㣬�򷵻�false
//    return false;
//}
//
//int main() {
//    int K, M, N;
//    cin >> K >> M >> N;
//
//    // ���δ���ÿ������
//    for (int k = 0; k < K; ++k) {
//        Dungeon dungeon;
//        dungeon.M = M;
//        dungeon.N = N;
//
//        // ��ʼ��visited����
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                dungeon.visited[i][j] = false;
//            }
//        }
//
//        // ��ȡ������Ϣ
//        for (int i = 0; i < M; ++i) {
//            for (int j = 0; j < N; ++j) {
//                cin >> dungeon.grid[i][j];
//            }
//        }
//
//        // ���DFS�����ɹ��������YES���������NO
//        if (dfs(dungeon)) {
//            cout << "YES" << endl;
//        }
//        else {
//            cout << "NO" << endl;
//        }
//    }
//
//    return 0;
//}
