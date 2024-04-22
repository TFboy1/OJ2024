//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//// 自定义比较函数，用于排序
//bool compare(string a, string b) {
//    return a + b > b + a;
//}
//
//// 求解最大整数
//string findMaxNumber(vector<int>& numbers) {
//    // 将数字转换为字符串
//    vector<string> nums_str;
//    for (int num : numbers) {
//        nums_str.push_back(to_string(num));
//    }
//
//    // 对字符串进行排序
//    sort(nums_str.begin(), nums_str.end(), compare);
//
//    // 拼接排序后的字符串
//    string result = "";
//    for (string num_str : nums_str) {
//        result += num_str;
//    }
//
//    return result;
//}
//
//int main() {
//    int N;
//    while (cin >> N && N != 0) {
//        vector<int> numbers(N);
//        for (int i = 0; i < N; ++i) {
//            cin >> numbers[i];
//        }
//
//        // 求解并输出最大整数
//        cout << findMaxNumber(numbers) << endl;
//    }
//    return 0;
//}
