//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    priority_queue<int, vector<int>, greater<int>> pq; // ��С�ѣ��洢ÿ����ͷ�Ľ�ˮʱ��
//    for (int i = 0; i < m; ++i) {
//        pq.push(0); // ��ʼʱ��������ͷ�Ľ�ˮʱ��Ϊ 0
//    }
//
//    for (int i = 0; i < n; ++i) {
//        int w;
//        cin >> w; // ��ǰͬѧ�Ľ�ˮ��
//
//        int t = pq.top(); // ȡ����ˮʱ����̵���ͷ
//        pq.pop(); // ������ͷ�Ľ�ˮʱ��Ӷ������Ƴ�
//
//        pq.push(t + w); // ���¸���ͷ�Ľ�ˮʱ�䣬�����·Żض���
//    }
//
//    int max_time = 0;
//    // ����ͬѧ����ˮ�󣬶����е�����ˮʱ�伴Ϊ��ʱ��
//    while (!pq.empty()) {
//        max_time = max(max_time, pq.top());
//        pq.pop();
//    }
//
//    cout << max_time << endl; // �����ʱ��
//
//    return 0;
//}
