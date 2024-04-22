//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    priority_queue<int, vector<int>, greater<int>> pq; // 最小堆，存储每个龙头的接水时间
//    for (int i = 0; i < m; ++i) {
//        pq.push(0); // 初始时，所有龙头的接水时间为 0
//    }
//
//    for (int i = 0; i < n; ++i) {
//        int w;
//        cin >> w; // 当前同学的接水量
//
//        int t = pq.top(); // 取出接水时间最短的龙头
//        pq.pop(); // 将该龙头的接水时间从队列中移除
//
//        pq.push(t + w); // 更新该龙头的接水时间，并重新放回队列
//    }
//
//    int max_time = 0;
//    // 所有同学接完水后，队列中的最大接水时间即为总时间
//    while (!pq.empty()) {
//        max_time = max(max_time, pq.top());
//        pq.pop();
//    }
//
//    cout << max_time << endl; // 输出总时间
//
//    return 0;
//}
