//#include<iostream>
//#include <string>
//using namespace std;
//int dp[100];
//
//bool is_bad(string s) {
//	return (s.find("4") != string::npos) || (s.find("62") != string::npos);
//}
//
//int main() {
//	int L, R;
//
//	while (true) {
//		int k = 0;
//		cin >> L >> R;
//		if (L == 0 && R == 0)
//		{
//			break;
//		}
//
//		else {
//			for (int i = L; i <= R; i++)
//			{
//
//				string dif = to_string(i);
//				if (is_bad(dif)) {
//					k++;
//				}
//
//			}
//			cout << R - L - k + 1 << endl;
//
//			/*dp[1] = 1;
//			for (int i = 2; i <= R; i++) {
//				dp[i] = dp[i - 1];
//			}*/
//		}
//	}
//
//}