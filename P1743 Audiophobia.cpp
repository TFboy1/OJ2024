///*
// * @Description: To iterate is human, to recurse divine.
// * @Autor: Recursion
// * @Date: 2022-06-08 18:59:29
// * @LastEditTime: 2022-06-08 21:46:05
// */
// /*
//  * @Description: To iterate is human, to recurse divine.
//  * @Autor: Recursion
//  * @Date: 2022-06-08 18:59:29
//  * @LastEditTime: 2022-06-08 20:47:14
//  */
//#include <iostream>
//#include<cstring>
//#define LL long long 
//using namespace std;
//
//const int INF = 1e9 + 10;
//const int N = 1e3 + 7;
//int a[N][N];
//
//int C, S, Q;
//int u, v, w;
//
//int main()
//{
//
//    int count = 0;
//    while (cin >> C >> S >> Q) {
//        count++;
//        memset(a, 0, sizeof(a));
//        for (int i = 1; i <= C; i++)
//            for (int j = 1; j <= C; j++)
//                if (i != j)
//                    a[i][j] = INF;
//        while (S--) {
//            cin >> u >> v >> w;
//            a[u][v] = w;
//            a[v][u] = w;
//        }
//        for (int k = 1; k <= C; k++)
//            for (int i = 1; i <= C; i++)
//                for (int j = 1; j <= C; j++)
//
//                    a[i][j] = min(a[i][j], max(a[i][k], a[k][j]));
//        cout << "Case #" << count << endl;
//        while (Q--) {
//            int x, y;
//            cin >> x >> y;
//
//            if (a[x][y] == INF) {
//                cout << "no path" << endl;
//                continue;
//            }
//            else
//                cout << a[x][y] << endl;
//        }
//    }
//
//
//    return 0;
//}