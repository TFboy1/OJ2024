//#include<iostream>
//#include<cmath>
//using namespace std;
//int main() {
//	int n, v[10000];
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> v[i];
//	}
//	int dp[10000];
//	int max_num=0;
//	dp[0] = v[0];
//	dp[1] = max(v[1], dp[0] + v[1]);
//	for (int i = 2; i < n; i++) {
//		dp[i]=max(v[i], dp[i - 1] + v[i]);
//		if (dp[i] > max_num)
//			max_num = dp[i];
//	}
//	cout<< max_num;
//}