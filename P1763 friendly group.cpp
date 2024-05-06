//#include <iostream>
//#include <vector>
//#include <unordered_set>
//
//using namespace std;
//
//vector<vector<int>> graph;
//vector<bool> visited;
//
//void dfs(int node, unordered_set<int>& friends) {
//    visited[node] = true;
//    friends.insert(node);
//    for (int neighbor : graph[node]) {
//        if (!visited[neighbor]) {
//            dfs(neighbor, friends);
//        }
//    }
//}
//
//int main() {
//    int T;
//    cin >> T;
//
//    for (int t = 1; t <= T; ++t) {
//        int n, m;
//        cin >> n >> m;
//
//        graph.assign(n + 1, vector<int>());
//        visited.assign(n + 1, false);
//
//        for (int i = 0; i < m; ++i) {
//            int x, y;
//            cin >> x >> y;
//            graph[x].push_back(y);
//            graph[y].push_back(x);
//        }
//
//        int max_friendly = 0;
//
//        for (int i = 1; i <= n; ++i) {
//            if (!visited[i]) {
//                unordered_set<int> friends;
//                dfs(i, friends);
//                int edges = 0;
//                for (int node : friends) {
//                    edges += graph[node].size();
//                }
//                edges /= 2; // Each edge is counted twice
//                int nodes = friends.size();
//                max_friendly += min(nodes, edges);
//            }
//        }
//
//        cout << "Case #" << t << ": " << max_friendly << endl;
//    }
//
//    return 0;
//}
