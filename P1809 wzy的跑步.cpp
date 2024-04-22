//#include<iostream>
//#include<cmath>
//#include<vector>
//using namespace std;
//
//int get_min(vector<int>& dp, int k, int start, int n) {
//    int min_x = dp[start];
//    for (int i = start; i < min(start + k, n + 1); i++) {
//        if (dp[i] < min_x) {
//            min_x = dp[i];
//        }
//    }
//    return min_x;
//}
//
//int main() {
//    int n, m, k, x;
//    cin >> n >> m >> k;
//    vector<int> v(n + 1, 0); // ʹ�������������飬����ʼ��Ϊ 0
//    for (int i = 1; i <= m; i++) {
//        cin >> x;
//        v[x] = 1;
//    }
//    vector<int> dp(n + 1); // ʹ��������������
//    if(v[1]==0)
//        dp[1] = 0;
//    if (v[1] == 1)
//        dp[1] = 1;
//    for (int j = 2; j <= n; j++) { // �޸�ѭ������ʼλ��Ϊ 2
//        if (v[j] == 0) {
//            dp[j] = get_min(dp, k, max(j - k, 1), j - 1); // �����ǰλ�ò���ˮ�ӣ�������Ծ�������� k
//        }
//        else {
//            dp[j] = get_min(dp, k, max(j - k, 1), j - 1) + 1; // �����ǰλ����ˮ�ӣ�����Ҫ������Ծ�������� k
//        }
//    }
//    cout << dp[n] << endl;
//
//    return 0;
//}
