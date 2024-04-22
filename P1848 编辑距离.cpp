//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//int minEditDistance(string A, string B) {
//    int m = A.length();
//    int n = B.length();
//
//    // ������̬�滮��
//    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
//
//    // ��ʼ���߽�����
//    for (int i = 0; i <= m; ++i) {
//        dp[i][0] = i;
//    }
//    for (int j = 0; j <= n; ++j) {
//        dp[0][j] = j;
//    }
//
//    // ��䶯̬�滮��
//    for (int i = 1; i <= m; ++i) {
//        for (int j = 1; j <= n; ++j) {
//            if (A[i - 1] == B[j - 1]) {
//                dp[i][j] = dp[i - 1][j - 1]; // �ַ���ͬ������Ҫ����
//            }
//            else {
//                // ѡ����롢ɾ�����滻�����е���Сֵ
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
//    // ���ú���������С�༭���벢������
//    cout << minEditDistance(A, B) << endl;
//
//    return 0;
//}
