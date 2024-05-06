//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//bool isSafe(vector<vector<int>>& graph, vector<int>& color, int v, int c) {
//    for (int i = 0; i < graph[v].size(); ++i) {
//        if (color[graph[v][i]] == c) {
//            return false;
//        }
//    }
//    return true;
//}
//
//int countGraphColoringUtil(vector<vector<int>>& graph, int m, vector<int>& color, int v) {
//    int n = graph.size();
//    if (v == n) {
//        return 1;
//    }
//
//    int ways = 0;
//    for (int c = 1; c <= m; ++c) {
//        if (isSafe(graph, color, v, c)) {
//            color[v] = c;
//            ways += countGraphColoringUtil(graph, m, color, v + 1);
//            color[v] = 0;
//        }
//    }
//    return ways;
//}
//
//int countGraphColoring(vector<vector<int>>& graph, int m) {
//    int n = graph.size();
//    vector<int> color(n, 0);
//    return countGraphColoringUtil(graph, m, color, 0);
//}
//
//int main() {
//    int n, k, m;
//    cin >> n >> k >> m;
//
//    vector<vector<int>> graph(n, vector<int>());
//    for (int i = 0; i < k; ++i) {
//        int u, v;
//        cin >> u >> v;
//        graph[u - 1].push_back(v - 1);
//        graph[v - 1].push_back(u - 1);
//    }
//
//    cout << countGraphColoring(graph, m) << endl;
//
//    return 0;
//}
