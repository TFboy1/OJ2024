//#include<bits/stdc++.h>
//#include <climits>
//#include <cstdlib>
//#include <utility>
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
//    ��Ĳ���
//    �������Ҫд�ݹ飬������solve����֮ǰ�����ĵݹ麯������solve�����е��á�
//*/
//char solve()
//{
//    // ����һ����������BFS
//    queue<pair<int, int>> q;
//
//    // ����һ���������ڱ���Ѿ����ʹ���λ��
//    bool visited[N][N] = { false };
//
//    // ����һ���������ڼ�¼����ÿ��λ�õ����·��
//    int distance[N][N] = { 0 };
//
//    // ��ǵ�ǰλ��Ϊ�ѷ���
//    visited[person_x][person_y] = true;
//
//    // ����ǰλ�ü������
//    q.push({ person_x, person_y });
//
//    // �����ĸ�����
//    int dx[] = { -1, 1, 0, 0 };
//    int dy[] = { 0, 0, -1, 1 };
//
//    // Ѱ������Ķ���
//    pair<int, int> nearestBean;
//    int minDistance = 101;
//
//    while (!q.empty()) {
//        // ȡ�������еĵ�һ��λ��
//        pair<int, int> current = q.front();
//        q.pop();
//
//        // ��鵱ǰλ���Ƿ��Ƕ���
//        if (a[current.first][current.second] == 2) {
//            minDistance = distance[current.first][current.second];
//            nearestBean = current;
//            break; // �ҵ�����Ķ��Ӻ�ֹͣ����
//        }
//
//        // �����ĸ�����
//        for (int i = 0; i < 4; ++i) {
//            int nx = current.first + dx[i];
//            int ny = current.second + dy[i];
//
//            // �����һ��λ���Ƿ�Ϸ�
//            if (nx >= 1 && nx <= szx && ny >= 1 && ny <= szy && !visited[nx][ny] && a[nx][ny] != 4) {
//                // �����һ��λ��Ϊ�ѷ��ʣ������㵽���λ�õ�·������
//                visited[nx][ny] = true;
//                distance[nx][ny] = distance[current.first][current.second] + 1;
//                q.push({ nx, ny });
//            }
//        }
//    }
//
//    // ���û���ҵ����ӣ�����ͣ��
//    if (minDistance == 101) return 'S';
//
//    // ����Ѿ�վ�ڶ����ϣ���ͣ��
//    if (nearestBean.first == person_x && nearestBean.second == person_y) return 'S';
//
//    // ���㵽������ľ���
//    int distanceGhost1 = abs(person_x - preghost1.first) + abs(person_y - preghost1.second);
//    int distanceGhost2 = abs(person_x - preghost2.first.first) + abs(person_y - preghost2.first.second);
//    distanceGhost2 = min(distanceGhost2, abs(person_x - preghost2.second.first) + abs(person_y - preghost2.second.second));
//
//    // ��������ܽ�������Զ���ķ����ƶ�
//    if (distanceGhost1 <= 2 || distanceGhost2 <= 2) {
//        if (nearestBean.first < person_x && a[person_x - 1][person_y] != 4) return 'U';
//        if (nearestBean.first > person_x && a[person_x + 1][person_y] != 4) return 'D';
//        if (nearestBean.second < person_y && a[person_x][person_y - 1] != 4) return 'L';
//        if (nearestBean.second > person_y && a[person_x][person_y + 1] != 4) return 'R';
//    }
//
//    // ������Ķ����ƶ���ȷ�������߽�ǽ��
//    if (nearestBean.first != person_x) {
//        if (nearestBean.first < person_x && a[person_x - 1][person_y] != 4) return 'U';
//        if (nearestBean.first > person_x && a[person_x + 1][person_y] != 4) return 'D';
//    }
//
//    if (nearestBean.second != person_y) {
//        if (nearestBean.second < person_y && a[person_x][person_y - 1] != 4) return 'L';
//        if (nearestBean.second > person_y && a[person_x][person_y + 1] != 4) return 'R';
//    }
//
//    // ����޷��ƶ���Ŀ��λ�ã�����ͣ��
//    return 'S';
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
