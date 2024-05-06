//#include <iostream>
//#include <vector>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//struct Ink {
//    int x, y;
//};
//
//vector<int> parent;
//
//int find(int u) {
//    if (parent[u] == u)
//        return u;
//    return parent[u] = find(parent[u]);
//}
//
//void unite(int u, int v) {
//    int rootU = find(u);
//    int rootV = find(v);
//    if (rootU != rootV)
//        parent[rootU] = rootV;
//}
//
//double distance(const Ink& a, const Ink& b) {
//    int dx = a.x - b.x;
//    int dy = a.y - b.y;
//    return sqrt(dx * dx + dy * dy);
//}
//
//double squareTimeToConnect(int n, vector<Ink>& inks) {
//    vector<pair<double, pair<int, int>>> edges;
//    for (int i = 0; i < n; ++i) {
//        for (int j = i + 1; j < n; ++j) {
//            edges.push_back({ distance(inks[i], inks[j]), {i, j} });
//        }
//    }
//
//    sort(edges.begin(), edges.end());
//
//    parent.resize(n);
//    for (int i = 0; i < n; ++i) {
//        parent[i] = i;
//    }
//
//    double maxWeight = 0.0;
//    for (const auto& edge : edges) {
//        int from = edge.second.first;
//        int to = edge.second.second;
//        if (find(from) != find(to)) {
//            unite(from, to);
//            maxWeight = max(maxWeight, edge.first);
//        }
//    }
//
//    return maxWeight * maxWeight;
//}
//
//int main() {
//    int T;
//    cin >> T;
//
//    while (T--) {
//        int n;
//        cin >> n;
//        vector<Ink> inks(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> inks[i].x >> inks[i].y;
//        }
//
//        cout << fixed << squareTimeToConnect(n, inks) << endl;
//    }
//
//    return 0;
//}
