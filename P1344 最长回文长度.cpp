//#include<iostream>
//#include<string>
//
//using namespace std;
//#define MAX 100
//int dp[MAX][MAX];
//
//int main() {
//	//�൱����� һ���ַ��������������ַ����� �����������
//	string s;
//	while (cin >> s)
//	{
//		int len = s.length();
//		//��Ҫ��ʼ��
//		// �±�Ϊ0 ����������ַ�����Ȼ�Ļ� dp[i-1][j-1]���������ˡ�
//		for (int i = 0; i <= len; i++)
//		{
//			dp[i][0] = 0;
//			dp[0][i] = 0;
//		}
//		//ע��������±��ϵ �ַ���ʱ����Ƚϣ�����dp[1]������� ���Ǽ���s[0]�����ַ��������
//		for (int i = 0; i < len; i++)
//		{
//			for (int j = 0; j < len; j++)
//			{
//				if (s[i] == s[len - 1 - j]) {
//					dp[i + 1][j + 1] = dp[i][j] + 1;
//				}
//				else {
//					//�õ�Сһ����ģ�� ������
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