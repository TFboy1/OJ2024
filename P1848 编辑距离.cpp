//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minEditDistance(string A, string B) {
//    int m = A.length();
//    int n = B.length();
//
//    // 创建动态规划表
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//
//    // 初始化边界条件
//    for (int i = 0; i <= m; ++i) {
//        dp[i][0] = i;
//    }
//    for (int j = 0; j <= n; ++j) {
//        dp[0][j] = j;
//    }
//
//    // 填充动态规划表
//    for (int i = 1; i <= m; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            if (A[i - 1] == B[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1]; // 字符相同，不需要操作
//            }
//            else {
//                // 选择插入、删除或替换操作中的最小值
//                dp[i][j] = 1 + min({ dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] });
//            }
//        }
//    }
//
//    return dp[m][n];
//}
//
//int main() {
//    string A, B;
//    cin >> A >> B;
//
//    // 调用函数计算最小编辑距离并输出结果
//    cout << minEditDistance(A, B) << endl;
//
//    return 0;
//}
