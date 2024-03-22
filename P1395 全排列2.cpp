////#include <iostream>
////#include <vector>
////#include <stack>
////using namespace std;
////
////vector<string> results;
////stack<string> mystack;
////
////void all_list(string n) {
////    if (n.length() == 2) {
////        results.push_back(n); // ������Ϊ2���ַ���ֱ����ӵ������
////        char temp = n[0];
////        n[0] = n[1];
////        n[1] = temp;
////        results.push_back(n); // ��ӽ�������ַ����������
////    }
////    else {
////        for (int i = 0; i < n.length(); i++) {
////            string first = n.substr(0, i);
////            string last = n.substr(i, 1);
////            all_list(first + last); // �޸ĺ������ô��ݵĲ���
////            while (!mystack.empty()) { // ����ջ�пշ�ʽ
////                string temp = mystack.top();
////                mystack.pop();
////                string a =  temp+last; // �����ַ���ƴ��
////                results.push_back(a);
////            }
////        }
////        mystack = stack<string>(); // ���ջ
////    }
////}
////
////int main() {
////    int n;
////    cin >> n;
////    all_list("");
////    while (!results.empty()) { // ����������ѭ��
////        cout << results.back() << endl;
////        results.pop_back();
////    }
////    return 0;
////}
//
//#include <iostream>
//#include <vector>
//#include <algorithm> 
//using namespace std;
//
//vector<string> results;
//
//void all_list(string prefix, string remaining) {
//    if (remaining.empty()) {
//        results.push_back(prefix); // ��ʣ�ಿ��Ϊ��ʱ��˵���Ѿ�������һ�����������У������������
//    }
//    else {
//        for (int i = 0; i < remaining.length(); i++) {
//            string new_prefix = prefix + remaining[i]; // ����ǰ�ַ���ӵ�ǰ׺��
//            string new_remaining = remaining.substr(0, i) + remaining.substr(i + 1); // ��ʣ�ಿ�����Ƴ���ǰ�ַ�
//            all_list(new_prefix, new_remaining); // �ݹ���ã�����ʣ�ಿ�ֵ�ȫ����
//        }
//    }
//}
//
//int main() {
//    int n;
//    while (cin >> n) {
//        string input;
//        for (int i = 1; i <= n; i++) {
//            input.push_back(i + '0');
//        }
//        all_list("", input); // ��ʼʱǰ׺Ϊ�գ�ʣ�ಿ��Ϊ�����ַ���
//        sort(results.begin(), results.end()); // �Խ����������
//        for (const auto& result : results) {
//            cout << result << endl;
//        }
//        results.clear(); // ��ս���Ա���һ��ʹ��
//    }
//    return 0;
//}
