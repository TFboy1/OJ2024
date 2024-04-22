//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> v(n + 1); // 存储每个村庄修建地道出口后能够消灭的敌人数量
//    vector<int> dp(n + 1, 0); // 动态规划数组，dp[i]表示前i个村庄能够消灭的最大敌人数量
//
//    for (int i = 1; i <= n; i++) {
//        cin >> v[i];
//    }
//
//    // 边界条件
//    dp[1] = v[1];
//    dp[2] = max(v[1], v[2]);
//
//    // 动态规划转移方程
//    for (int i = 3; i <= n; i++) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
//    }
//
//    cout << dp[n] << endl; // 输出最终结果
//
//    return 0;
//}
