//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int gcd(int a, int b) {
//    while (b != 0) {
//        int temp = b;
//        b = a % b;
//        a = temp;
//    }
//    return a;
//}
//
//int longest_co_prime_subsequence(int n, vector<int>& a) {
//    vector<int> dp(n, 1);
//
//    for (int i = 1; i < n; ++i) {
//        for (int j = 0; j < i; ++j) {
//            if (gcd(a[i], a[j]) == 1) {
//                dp[i] = max(dp[i], dp[j] + 1);
//            }
//        }
//    }
//
//    return *max_element(dp.begin(), dp.end());
//}
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> a(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> a[i];
//    }
//
//    int ans = longest_co_prime_subsequence(n, a);
//    cout << ans << endl;
//
//    return 0;
//}
