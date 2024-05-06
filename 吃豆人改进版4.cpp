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
//    ��Ĳ���
//    �������Ҫд�ݹ飬������solve����֮ǰ�����ĵݹ麯������solve�����е��á�
//*/
//// ���嶹�ӵ�����ṹ��
//struct Bean {
//    int x, y;
//};
//
//// �����Ƿ��ڿ��·�Χ��
//bool is_ghost_nearby(int person_x, int person_y, int ghost_x, int ghost_y) {
//    // �����ͳԶ��˵������پ���
//    int distance = abs(person_x - ghost_x) + abs(person_y - ghost_y);
//    // �������С�ڵ���2������ڿ��·�Χ��
//    return distance <= 2;
//}
//
//char solve()
//{
//    // ��ǰ�Զ��˵�����
//    int curr_x = person_x;
//    int curr_y = person_y;
//
//    // ������ͼ�����ҹ��λ��
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= 40; ++j) {
//            // �����ǰλ���ǹ������ڿ��·�Χ��
//            if (a[i][j] == 8 && is_ghost_nearby(curr_x, curr_y, i, j)) {
//                // ���Զ�ܹ�
//                // ����Ϸ��Ƿ�ȫ�������ƶ��Ϸ�
//                if (a[curr_x - 1][curr_y] != 8 && a[curr_x - 1][curr_y] != 4) {
//                    return 'U';
//                }
//                // ����·��Ƿ�ȫ�������ƶ��·�
//                else if (a[curr_x + 1][curr_y] != 8 && a[curr_x + 1][curr_y] != 4) {
//                    return 'D';
//                }
//                // ������Ƿ�ȫ�������ƶ���
//                else if (a[curr_x][curr_y - 1] != 8 && a[curr_x][curr_y - 1] != 4) {
//                    return 'L';
//                }
//                // ����ҷ��Ƿ�ȫ�������ƶ��ҷ�
//                else if (a[curr_x][curr_y + 1] != 8 && a[curr_x][curr_y + 1] != 4) {
//                    return 'R';
//                }
//                // ����ĸ������й��ǽ�����ѡ��һ�������ƶ�
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
//    // ����һ����ά��������¼���ӵ�״̬����ʼ��Ϊ false
//    bool visited[20][40] = { false };
//
//    // ����һ���������洢�����ʵĶ���
//    std::queue<Bean> beansQueue;
//
//    // ������ͼ�������ж��Ӽ������
//    for (int i = 1; i <= 20; ++i) {
//        for (int j = 1; j <= 40; ++j) {
//            if (a[i][j] == 2) {
//                beansQueue.push({ i, j });
//            }
//        }
//    }
//
//    // ������в�Ϊ�գ�˵�����ж���δ������
//    if (!beansQueue.empty()) {
//        // ����һ����������¼�Զ��˵��������ӵ���̾���
//        std::vector<std::vector<int>> distance(20, std::vector<int>(40, -1));
//
//        // ��ǵ�ǰλ���Ѿ����ʹ�
//        visited[curr_x][curr_y] = true;
//        distance[curr_x][curr_y] = 0;
//
//        // ����һ����������¼����Ķ��ӵľ��������
//        int minDistance = INT_MAX;
//        int minBean_x = -1;
//        int minBean_y = -1;
//
//        // ����һ����������¼��һ�����ƶ�����
//        char nextMove = '\0';
//
//        // ����һ������������Ƿ��ҵ��˿ɴ�Ķ���
//        bool foundBean = false;
//
//        // ʹ�ù����������������ͼ���ҵ��������ж��ӵ����·��
//        while (!beansQueue.empty()) {
//            // ����һ������
//            Bean bean = beansQueue.front();
//            beansQueue.pop();
//
//            // ��ȡ��ǰ���ӵ�����
//            int bean_x = bean.x;
//            int bean_y = bean.y;
//
//            // ���㵱ǰ���ӵ��Զ��˵ľ���
//            int dist = distance[curr_x][curr_y] + abs(curr_x - bean_x) + abs(curr_y - bean_y);
//
//            // ���µ���ǰ���ӵ���̾���
//            if (dist < minDistance) {
//                minDistance = dist;
//                minBean_x = bean_x;
//                minBean_y = bean_y;
//            }
//
//            // ����ǰ���ӱ��Ϊ�ѷ���
//            visited[bean_x][bean_y] = true;
//
//            // ����ǰ���ӵ���Χ���Ӽ������
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
//        // ����ҵ�������Ķ��ӣ��������ŵ��ƶ�����
//        if (minBean_x != -1 && minBean_y != -1) {
//            // ����������ӵ�����͵�ǰ�Զ��˵���������ƶ�����
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
//        // ����ҵ������ŵ��ƶ������򷵻ظ÷���
//        if (nextMove != '\0') {
//            return nextMove;
//        }
//    }
//
//    // ���û�ж��ӿɹ��ԣ�����ԭ�еĲ����ƶ�
//
//    // ����Ϸ��Ƿ��ж��ӣ������ƶ��Ϸ�
//    if (a[curr_x - 1][curr_y] == 2) {
//        return 'U';
//    }
//    // ����·��Ƿ��ж��ӣ������ƶ��·�
//    else if (a[curr_x + 1][curr_y] == 2) {
//        return 'D';
//    }
//    // ������Ƿ��ж��ӣ������ƶ���
//    else if (a[curr_x][curr_y - 1] == 2) {
//        return 'L';
//    }
//    // ����ҷ��Ƿ��ж��ӣ������ƶ��ҷ�
//    else if (a[curr_x][curr_y + 1] == 2) {
//        return 'R';
//    }
//    // ����ĸ�����û�ж��ӣ������ѡ��һ�������ƶ�
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
