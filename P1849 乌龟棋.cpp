///*
//************************************
//***********emu^w^***********
//
//*/
//
//#include <iostream>
//using namespace std;
//#define x first
//#define y second
//const int P = 13131;
//#define ll long long
//const int mod = 1E6 + 7;
//const int INF = 0x3f, sINF = 0x3f3f3f3f;
//typedef unsigned long long ULL;
//typedef pair<int, int> PII;
//typedef pair<long long, long long> PLL;
//int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
////
//const int N = 41;
//int f[N][N][N][N];
//int card[5], q[400];
//int n, m;
//
//int main()
//{
//    cin >> n >> m;
//    for (int i = 0; i < n; i++) cin >> q[i];
//
//    while (m--)
//    {
//        int temp;
//        cin >> temp;
//        card[temp]++;
//    }
//
//    for (int a = 0; a <= card[1]; a++)
//        for (int b = 0; b <= card[2]; b++)
//            for (int c = 0; c <= card[3]; c++)
//                for (int d = 0; d <= card[4]; d++)
//                {
//                    int temp = q[a + 2 * b + 3 * c + 4 * d];
//                    int& v = f[a][b][c][d];
//                    v = temp;
//                    if (a) v = max(v, f[a - 1][b][c][d] + temp);
//                    if (b) v = max(v, f[a][b - 1][c][d] + temp);
//                    if (c) v = max(v, f[a][b][c - 1][d] + temp);
//                    if (d) v = max(v, f[a][b][c][d - 1] + temp);
//                }
//
//    cout << f[card[1]][card[2]][card[3]][card[4]];
//}