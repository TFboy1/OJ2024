//#include<algorithm>
//#include <iostream>
//#include<vector>
//#include<map>
//#include<cmath>
//#define MAX_NODES 1000
//using namespace std;
//map<int, vector<int>> tree;
//
////class Node {
////public:
////    int num;
////    int leftChild;
////    int rightChild;
////    Node(int num=0 ,int leftChild =0,int rightChild=0) {
////        this->num = num;
////        this->leftChild = leftChild;
////        this->rightChild = rightChild;
////    }
////};
//
//int max_len=1;
//
//void find_depth(int root,int len) {
//    max_len = max(len, max_len);
//    for (int child : tree[root]) {
//        find_depth(child, len + 1);
//    }
//
//}
//int main() {
//    int n;
//    int len = 1;
//    int u,v;
//    cin >> n;
//    for (int i = 1; i <= n - 1; i++) {
//        cin >> u >> v;
//        tree[u].push_back(v);
//    }
//
//   find_depth(1,len);
//   cout << max_len-1;
//    return 0;
//}
//
