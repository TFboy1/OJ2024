//#include<iostream>
//#include<vector>
//#include<algorithm>
//using namespace std;
//
//int main() {
//    int n;
//    cin >> n;
//
//    vector<int> v(n + 1); // �洢ÿ����ׯ�޽��ص����ں��ܹ�����ĵ�������
//    vector<int> dp(n + 1, 0); // ��̬�滮���飬dp[i]��ʾǰi����ׯ�ܹ����������������
//
//    for (int i = 1; i <= n; i++) {
//        cin >> v[i];
//    }
//
//    // �߽�����
//    dp[1] = v[1];
//    dp[2] = max(v[1], v[2]);
//
//    // ��̬�滮ת�Ʒ���
//    for (int i = 3; i <= n; i++) {
//        dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
//    }
//
//    cout << dp[n] << endl; // ������ս��
//
//    return 0;
//}
