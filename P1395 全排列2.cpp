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
////        results.push_back(n); // 将长度为2的字符串直接添加到结果中
////        char temp = n[0];
////        n[0] = n[1];
////        n[1] = temp;
////        results.push_back(n); // 添加交换后的字符串到结果中
////    }
////    else {
////        for (int i = 0; i < n.length(); i++) {
////            string first = n.substr(0, i);
////            string last = n.substr(i, 1);
////            all_list(first + last); // 修改函数调用传递的参数
////            while (!mystack.empty()) { // 修正栈判空方式
////                string temp = mystack.top();
////                mystack.pop();
////                string a =  temp+last; // 修正字符串拼接
////                results.push_back(a);
////            }
////        }
////        mystack = stack<string>(); // 清空栈
////    }
////}
////
////int main() {
////    int n;
////    cin >> n;
////    all_list("");
////    while (!results.empty()) { // 修正结果输出循环
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
//        results.push_back(prefix); // 当剩余部分为空时，说明已经生成了一个完整的排列，将其加入结果中
//    }
//    else {
//        for (int i = 0; i < remaining.length(); i++) {
//            string new_prefix = prefix + remaining[i]; // 将当前字符添加到前缀中
//            string new_remaining = remaining.substr(0, i) + remaining.substr(i + 1); // 从剩余部分中移除当前字符
//            all_list(new_prefix, new_remaining); // 递归调用，处理剩余部分的全排列
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
//        all_list("", input); // 初始时前缀为空，剩余部分为整个字符串
//        sort(results.begin(), results.end()); // 对结果进行排序
//        for (const auto& result : results) {
//            cout << result << endl;
//        }
//        results.clear(); // 清空结果以便下一次使用
//    }
//    return 0;
//}
