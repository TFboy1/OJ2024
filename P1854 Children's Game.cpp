//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//
//using namespace std;
//
//// �Զ���ȽϺ�������������
//bool compare(string a, string b) {
//    return a + b > b + a;
//}
//
//// ����������
//string findMaxNumber(vector<int>& numbers) {
//    // ������ת��Ϊ�ַ���
//    vector<string> nums_str;
//    for (int num : numbers) {
//        nums_str.push_back(to_string(num));
//    }
//
//    // ���ַ�����������
//    sort(nums_str.begin(), nums_str.end(), compare);
//
//    // ƴ���������ַ���
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
//        // ��Ⲣ����������
//        cout << findMaxNumber(numbers) << endl;
//    }
//    return 0;
//}
