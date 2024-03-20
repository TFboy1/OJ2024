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
////	// �ָ����������������������
////	string left_in_order = in_order.substr(0, root_idx);
////	string right_in_order = in_order.substr(root_idx + 1);
////
////	// �ָ����������������������
////	string left_pre_order = pre_order.substr(1, root_idx);
////	string right_pre_order = pre_order.substr(root_idx + 1);
////	createTree(left_in_order, left_pre_order);
////	createTree(right_in_order, right_pre_order);
////	//for (int i = 0; i <= pre_order.size() - 1; i++)
////	//	tree[].push_back();
////	tree[root] = { left_in_order, right_in_order };
////}
////string post_order;
//////�������
////string post_order_representation(string leftChild, string rightChild, char root) {
////	if (tree.find(root) == tree.end()) return ""; // ������в����ڸýڵ㣬�򷵻ؿ��ַ���
////	leftChild = post_order_representation(tree[root][0], tree[root][1], tree[root][0][0]); // �ݹ��ȡ�������ĺ��������ʾ
////	rightChild = post_order_representation(tree[root][1], tree[root][1], tree[root][1][0]); // �ݹ��ȡ�������ĺ��������ʾ
////	return leftChild + rightChild + root; // ����ƴ�Ӻ�ĺ��������ʾ
////}
////
////int main() {
////	string in_order, pre_order;
////	
////	cin >> in_order>>pre_order;
////	createTree(in_order,pre_order);
////	char root = pre_order[0]; // ��ȡ���ڵ�
////	post_order= post_order_representation(tree[root][0], tree[root][1], root); // �����������ĺ��������ʾ
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
//    if (root == nullptr) return ""; // ����ڵ�Ϊ�գ��򷵻ؿ��ַ���
//    string leftChild = post_order_representation(root->left); // �ݹ��ȡ�������ĺ��������ʾ
//    string rightChild = post_order_representation(root->right); // �ݹ��ȡ�������ĺ��������ʾ
//    return leftChild + rightChild + root->val; // ����ƴ�Ӻ�ĺ��������ʾ
//}
//
//int main() {
//    string in_order, pre_order;
//   
//    cin >> in_order >> pre_order;
//
//    TreeNode* root = createTree(in_order, pre_order);
//    string post_order = post_order_representation(root); // �����������ĺ��������ʾ
//    cout << post_order << endl;
//
//    return 0;
//}
