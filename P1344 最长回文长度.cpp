//#include<iostream>
//#include<string>
//
//using namespace std;
//#define MAX 100
//int dp[MAX][MAX];
//
//int main() {
//	//相当于求解 一个字符串和他的逆序字符串的 最长公共子序列
//	string s;
//	while (cin >> s)
//	{
//		int len = s.length();
//		//需要初始化
//		// 下标为0 代表考虑零个字符。不然的话 dp[i-1][j-1]超出数组了。
//		for (int i = 0; i <= len; i++)
//		{
//			dp[i][0] = 0;
//			dp[0][i] = 0;
//		}
//		//注意这里的下标关系 字符串时从零比较，但是dp[1]代表的是 考虑加入s[0]处的字符的情况。
//		for (int i = 0; i < len; i++)
//		{
//			for (int j = 0; j < len; j++)
//			{
//				if (s[i] == s[len - 1 - j]) {
//					dp[i + 1][j + 1] = dp[i][j] + 1;
//				}
//				else {
//					//得到小一级规模中 最长的情况
//					dp[i + 1][j + 1] = dp[i + 1][j] > dp[i][j + 1] ? dp[i + 1][j] : dp[i][j + 1];
//				}
//
//			}
//
//		}
//	
//
//		cout << dp[len][len] << endl;
//	}
//	return 0;
//}