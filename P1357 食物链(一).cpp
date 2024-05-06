//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//vector<vector<int>> graph;
//vector<bool> visited;
//int maxChainLength;
//
//void dfs(int node, int chainLength) {
//    visited[node] = true;
//    maxChainLength = max(maxChainLength, chainLength);
//
//    for (int neighbor : graph[node]) {
//        if (!visited[neighbor]) {
//            dfs(neighbor, chainLength + 1);
//        }
//    }
//    visited[node] = false; // Reset visited status for backtracking
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//        graph.assign(n + 1, vector<int>());
//        visited.assign(n + 1, false);
//        maxChainLength = 0;
//
//        for (int i = 0; i < m; ++i) {
//            int a, b;
//            cin >> a >> b;
//            graph[a].push_back(b);
//        }
//
//        for (int i = 1; i <= n; ++i) {
//            dfs(i, 1);
//        }
//
//        cout << maxChainLength << endl;
//    
//
//    return 0;
//}
