////#include<iostream>
////#include<algorithm>
////using namespace std;
////
////class Node {
////public:
////    int parent;
////    int num;
////
////    Node(int parent = 0, int num = 0) {
////        this->num = num;
////        this->parent = parent;
////    }
////};
////
////const int MAX_NODES = 1000; // 根据需要设定最大节点数
////
////int len[MAX_NODES];
////bool compare(Node& x1, Node& x2) {
////    return x1.num < x2.num;
////}
////
////bool compare1(int x1, int x2) {
////    return x1 < x2;
////}
////
////void calculate_depth(Node treeNodes[], int n) {
////    for (int i = n-1; i >=0; i--) {
////        int length = 0;
////        Node current = treeNodes[i];
////
////        // 在循环内更新 node.parent 的值
////        while (current.parent != 0) {
////            length++;
////            current = treeNodes[current.parent-1];
////        }
////        len[i] = length;
////    }
////}
////
////int main() {
////    int n;
////
////    int parent, num;
////    cin >> n;
////    Node treeNodes[MAX_NODES];
////    treeNodes[0] = Node(0, 1);
////
////    for (int i = 1; i < n; i++) {
////        cin >> parent >> num;
////        treeNodes[i] = Node(parent, num);
////    }
////
////    int max = 0;
////    sort(treeNodes, treeNodes + n, compare);
////    calculate_depth(treeNodes, n);
////    sort(len, len + n, compare1);
////    cout << len[n-1];
////
////    return 0;
////}
//#include<iostream>
//#include <vector>
//#include<cmath>
//using namespace std;
//vector<vector<int>> tree;
//
//int dfs(int u) {	
//	int dep = 0;
//	for (int i = 0; i < tree[u].size(); i++) {
//		dep = max(dep, dfs(tree[u][i]) + 1);
//	}
//	return dep;
//}
//int main() {
//	
//	int n;
//	cin >> n;
//	tree.resize(n + 1);
//	int u, v;
//	for (int i = 1; i <= n - 1; i++) {
//		cin >> u >> v;
//		tree[u].push_back(v);
//	}
//	cout << dfs(1) << endl;
//
//
//}