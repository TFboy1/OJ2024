////#include<iostream>
////#include<map>
////#include<vector>
////#define MAXNUM 100
////using namespace std;
////map<char, vector<string>> tree;
////
////void createTree(string in_order,string pre_order) {
////	if (in_order.empty() || pre_order.empty()) return;
////	char root = pre_order[0];
////	int root_idx = in_order.find(pre_order[0]);
////	// 分割左右子树的中序遍历序列
////	string left_in_order = in_order.substr(0, root_idx);
////	string right_in_order = in_order.substr(root_idx + 1);
////
////	// 分割左右子树的先序遍历序列
////	string left_pre_order = pre_order.substr(1, root_idx);
////	string right_pre_order = pre_order.substr(root_idx + 1);
////	createTree(left_in_order, left_pre_order);
////	createTree(right_in_order, right_pre_order);
////	//for (int i = 0; i <= pre_order.size() - 1; i++)
////	//	tree[].push_back();
////	tree[root] = { left_in_order, right_in_order };
////}
////string post_order;
//////后序遍历
////string post_order_representation(string leftChild, string rightChild, char root) {
////	if (tree.find(root) == tree.end()) return ""; // 如果树中不存在该节点，则返回空字符串
////	leftChild = post_order_representation(tree[root][0], tree[root][1], tree[root][0][0]); // 递归获取左子树的后序遍历表示
////	rightChild = post_order_representation(tree[root][1], tree[root][1], tree[root][1][0]); // 递归获取右子树的后序遍历表示
////	return leftChild + rightChild + root; // 返回拼接后的后序遍历表示
////}
////
////int main() {
////	string in_order, pre_order;
////	
////	cin >> in_order>>pre_order;
////	createTree(in_order,pre_order);
////	char root = pre_order[0]; // 获取根节点
////	post_order= post_order_representation(tree[root][0], tree[root][1], root); // 计算整棵树的后序遍历表示
////	cout << "Post-order traversal representation: " << post_order << endl;
////
////	
////
////}
//#include<iostream>
//#include<map>
//#include<vector>
//#include<string>
//using namespace std;
//
//class TreeNode {
//public:
//    char val;
//    TreeNode* left;
//    TreeNode* right;
//
//    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
//};
//
//TreeNode* createTree(string in_order, string pre_order) {
//    if (in_order.empty() || pre_order.empty()) return nullptr;
//    char root_val = pre_order[0];
//    int root_idx = in_order.find(root_val);
//    string left_in_order = in_order.substr(0, root_idx);
//    string right_in_order = in_order.substr(root_idx + 1);
//    string left_pre_order = pre_order.substr(1, root_idx);
//    string right_pre_order = pre_order.substr(root_idx + 1);
//
//    TreeNode* root = new TreeNode(root_val);
//    root->left = createTree(left_in_order, left_pre_order);
//    root->right = createTree(right_in_order, right_pre_order);
//
//    return root;
//}
//
//string post_order_representation(TreeNode* root) {
//    if (root == nullptr) return ""; // 如果节点为空，则返回空字符串
//    string leftChild = post_order_representation(root->left); // 递归获取左子树的后序遍历表示
//    string rightChild = post_order_representation(root->right); // 递归获取右子树的后序遍历表示
//    return leftChild + rightChild + root->val; // 返回拼接后的后序遍历表示
//}
//
//int main() {
//    string in_order, pre_order;
//   
//    cin >> in_order >> pre_order;
//
//    TreeNode* root = createTree(in_order, pre_order);
//    string post_order = post_order_representation(root); // 计算整棵树的后序遍历表示
//    cout << post_order << endl;
//
//    return 0;
//}
