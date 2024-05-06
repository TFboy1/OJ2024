////#include <iostream>
////#include <vector>
////#include <climits>
////using namespace std;
////int get_min(vector<int> v,int k) {
////    int min=v[1];
////    int n=1;
////    for (int i = 1; i < k; i++) {
////        if (v[i] < min) {
////			min=v[i];
////            n = i;
////		}
////
////    }
////    return n;
////}
////int main() {
////    int N;
////    int HP;
////    cin >> N;
////    vector<int> a(N + 1);
////    for (int i = 1; i <= N; ++i) {
////        cin >> a[i];
////    }
////    HP = 0;
////    for (int i = 2; i <= N; i++) {
////        HP = HP + a[i] + a[get_min(a, i)];
////    }
////    cout << HP << endl;
////    return 0;
////}
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <algorithm>
//
//using namespace std;
//
//const int MAXN = 100005; // 最大会场数量
//const int INF = 1e9; // 无穷大值
//
//struct Edge {
//    int to, cost;
//    Edge(int t, int c) : to(t), cost(c) {}
//};
//
//vector<Edge> graph[MAXN];
//bool visited[MAXN];
//int minCost[MAXN];
//
//int prim(int start, int N) {
//    for (int i = 1; i <= N; ++i) {
//        minCost[i] = INF;
//        visited[i] = false;
//    }
//
//    minCost[start] = 0;
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    pq.push({ 0, start });
//
//    int totalCost = 0;
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//
//        if (visited[u]) continue;
//        visited[u] = true;
//        totalCost += minCost[u];
//
//        for (const Edge& e : graph[u]) {
//            int v = e.to;
//            int cost = e.cost;
//
//            if (!visited[v] && cost < minCost[v]) {
//                minCost[v] = cost;
//                pq.push({ cost, v });
//            }
//        }
//    }
//
//    return totalCost;
//}
//
//int main() {
//    int N;
//    cin >> N;
//
//    vector<int> A(N + 1);
//    for (int i = 1; i <= N; ++i) {
//        cin >> A[i];
//    }
//
//    // 构建图
//    for (int i = 1; i <= N; ++i) {
//        for (int j = i + 1; j <= N; ++j) {
//            int cost = A[i] + A[j];
//            graph[i].emplace_back(j, cost);
//            graph[j].emplace_back(i, cost);
//        }
//    }
//
//    // 从任意一个会场开始，这里选择从第一个会场开始
//    int result = prim(1, N);
//    cout << result << endl;
//
//    return 0;
//}
