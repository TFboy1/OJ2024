//#include<iostream>
//#include<cmath>
//using namespace std;
//int get_max(int v[],int k) {
//	int max = 0;
//	for (int i = 0; i < k; i++) {
//		if (v[i] > max) {
//			max = v[i];
//		}
//	}
//	return max;
//}
//int main() {
//	int N, M;
//	int P, X;
//	int v[100] = {0};
//	int dp[100];
//	cin >> N >> M;
//	for (int i = 0; i < N; i++) {
//		cin >> v[i];
//	}
//	dp[0] = 0;
//	for (int i = 1; i < N; i++) {
//		dp[i] = max(get_max(dp, i), get_max(dp, i)+v[i]);
//	}
//	cout << M - dp[N-1];
//}