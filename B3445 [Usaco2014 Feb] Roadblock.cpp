//
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <climits>
//
//using namespace std;
//
//// Structure to represent an edge in the graph
//struct Edge {
//    int to, weight;
//};
//
//// Function to add an undirected edge to the graph
//void addEdge(vector<vector<Edge>>& graph, int from, int to, int weight) {
//    graph[from].push_back({ to, weight });
//    graph[to].push_back({ from, weight });
//}
//
//// Dijkstra's algorithm to find the shortest path from source to destination
//int dijkstra(const vector<vector<Edge>>& graph, int source, int destination) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//    vector<int> dist(graph.size(), INT_MAX);
//    pq.push({ 0, source });
//    dist[source] = 0;
//
//    while (!pq.empty()) {
//        int u = pq.top().second;
//        pq.pop();
//
//        for (auto& edge : graph[u]) {
//            int v = edge.to;
//            int weight = edge.weight;
//            if (dist[u] + weight < dist[v]) {
//                dist[v] = dist[u] + weight;
//                pq.push({ dist[v], v });
//            }
//        }
//    }
//
//    return dist[destination];
//}
//
//int main() {
//    int N, M;
//    cin >> N >> M;
//
//    vector<vector<Edge>> graph(N + 1);
//
//    for (int i = 0; i < M; ++i) {
//        int A, B, L;
//        cin >> A >> B >> L;
//        addEdge(graph, A, B, L);
//    }
//
//    // Find the shortest path without any modifications
//    int originalShortestPath = dijkstra(graph, 1, N);
//
//    int maxIncrease = 0;
//
//    // Try doubling the length of each edge and find the maximum increase in shortest path
//    for (int i = 1; i <= N; ++i) {
//        for (auto& edge : graph[i]) {
//            int originalWeight = edge.weight;
//            edge.weight *= 2; // Double the weight of the edge
//
//            // Find the shortest path with the modified edge
//            int modifiedShortestPath = dijkstra(graph, 1, N);
//
//            // Update the maximum increase in shortest path
//            maxIncrease = max(maxIncrease, modifiedShortestPath - originalShortestPath);
//
//            edge.weight = originalWeight; // Restore the original weight of the edge
//        }
//    }
//
//    cout << maxIncrease << endl;
//
//    return 0;
//}
