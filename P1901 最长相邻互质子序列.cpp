//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//
//#define maxn 100050
//using namespace std;
//
//vector<int> vc[maxn];
//
//// ��ʼ����������
//void init() {
//    for (int i = 2; i < maxn; i++) {
//        for (int j = i; j < maxn; j += i)
//            vc[j].push_back(i);
//    }
//}
//
//int main() {
//    init();
//
//    int n;
//    cin >> n;
//
//    int a[maxn], dp[maxn];
//    memset(dp, 0, sizeof(dp)); // ��ʼ����̬�滮����
//
//    for (int i = 1; i <= n; i++)
//        cin >> a[i];
//
//    for (int i = 1; i <= n; i++) {
//        for (int j = 0; j < vc[a[i]].size(); j++) {
//            int factor = vc[a[i]][j];
//            dp[factor] = 0; // �����������ӵ�ֵΪ0����ʾ������
//        }
//        for (int j = 0; j < vc[a[i]].size(); j++) {
//            int factor = vc[a[i]][j];
//            dp[factor] = max(dp[factor], dp[factor] + 1);
//        }
//    }
//
//    int ans = 1;
//    for (int i = 0; i < maxn; i++)
//        ans = max(ans, dp[i]);
//    cout << ans << endl;
//
//    return 0;
//}
