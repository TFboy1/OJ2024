//#include <iostream>
//#include <vector>
//#include <queue>
//#include <limits>
//
//using namespace std;
//
//const int INF = numeric_limits<int>::max();
//
//struct Edge {
//    int to, weight;
//    Edge(int t, int w) : to(t), weight(w) {}
//};
//
//vector<vector<Edge>> graph;
//vector<int> dijkstra(int start) {
//    int n = graph.size();
//    vector<int> dist(n, INF);
//    vector<int> maxNoise(n, 0); // 记录路径中的最大噪声值
//    dist[start] = 0;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push({ 0, start });
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        int d = pq.top().first;
//        pq.pop();
//
//        if (d > dist[u]) continue;
//
//        for (const Edge& e : graph[u]) {
//            int v = e.to;
//            int w = e.weight;
//
//            if (max(dist[u], w) < dist[v]) {
//                dist[v] = max(dist[u], w);
//                maxNoise[v] = max(maxNoise[u], w); // 更新最大噪声值
//                pq.push({ dist[v], v });
//            }
//        }
//    }
//
//    return maxNoise;
//}
//
//int main() {
//    int C, S, Q;
//    cin >> C >> S >> Q;
//
//    graph.resize(C + 1);
//
//    for (int i = 0; i < S; ++i) {
//        int u, v, w;
//        cin >> u >> v >> w;
//        graph[u].emplace_back(v, w);
//        graph[v].emplace_back(u, w); // 无向图
//    }
//
//    vector<int> maxNoise = dijkstra(1);
//
//    for (int i = 0; i < Q; ++i) {
//        int a, b;
//        cin >> a >> b;
//        if (maxNoise[b] == 0) {
//            cout << "no path" << endl;
//        }
//        else {
//            cout << maxNoise[b] << endl;
//        }
//    }
//
//    return 0;
//}
