///*
// * @Description: To iterate is human, to recurse divine.
// * @Autor: Recursion
// * @Date: 2022-06-05 22:02:51
// * @LastEditTime: 2022-06-06 14:09:04
// */
//#include <bits/stdc++.h>
//#define LL long long 
//using namespace std;
//const int maxn = 1e6 + 10;
//const int mod = 1e9 + 7;
//const int INF = 1e9 + 10;
//const int N = 1e6;
//
//int n, q;
//LL w[N];
//LL s[N];
//int sum[N];
//
//int main()
//{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
//
//    cin >> n >> q;
//
//    for (int i = 1; i <= n; i++) {
//        cin >> w[i];
//        sum[i] += sum[i - 1] + w[i];
//    }
//
//    while (q--) {
//        int x;
//        cin >> x;
//        int pos = lower_bound(sum + 1, sum + 1 + n, x) - sum - 1;
//
//        cout << pos + 1 << " ";
//    }
//
//
//
//
//
//
//    return 0;
//}