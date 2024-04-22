//////#include<iostream>
//////#include <string>
//////using namespace std;
//////bool is_bad(std::string number) {
//////	for (int i = 0; i < number.size(); i++) {
//////		if (number.substr(i, 2) == "62" || number.substr(i, 1) == "4") {
//////			return false;
//////		}
//////	}
//////	return true;
//////}
//////int main() {
//////	int L, R;
//////	cin >> L >> R;
//////	if (L == 0 && R == 0)
//////		return 1;
//////	else {
//////	int count = 0;
//////	for (int i = L; i <= R; i++) {
//////		if (is_bad(to_string(i))) count++;
//////	}
//////	cout << count << endl;
//////	}
//////
//////}
////#include <iostream>
////#include <vector>
////#include <string>
////using namespace std;
////
////int count_good_numbers(int L, int R) {
////    vector<int> dp(R + 1);
////    dp[0] = 1; // 初始化，空字符串也是一种满足条件的数
////
////    // 计算不包含坏数字的数的个数
////    for (int i = 1; i <= R; ++i) {
////        dp[i] = dp[i - 1]; // 初始化为前一个数的个数
////
////        string str = to_string(i);
////        if (str.find("4") != string::npos || str.find("62") != string::npos) {
////            // 如果 i 包含坏数字，则跳过
////            continue;
////        }
////
////        // 如果 i 不包含坏数字，则将当前数的个数累加到前一个数的个数中
////        dp[i] += dp[i - 1];
////    }
////
////    // 区间 [L, R] 中不包含坏数字的数的个数为 dp[R] - dp[L-1]
////    return L > 0 ? dp[R] - dp[L - 1] : dp[R];
////}
////
////int main() {
////    int L, R;
////    while (cin >> L >> R && (L != 0 || R != 0)) {
////        cout << count_good_numbers(L, R) << endl;
////    }
////    return 0;
////}
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//bool isBadNumber(int num) {
//    string str = to_string(num);
//    return str.find("4") != string::npos || (str.find("62") != string::npos);
//}
//
//int countGoodNumbers(int L, int R) {
//    int count = 0;
//    for (int i = L; i <= R; ++i) {
//        if (!isBadNumber(i)) {
//            count++;
//        }
//    }
//    return count;
//}
//
//int main() {
//    int L, R;
//    while (true) {
//        cin >> L >> R;
//        if (L == 0 && R == 0) {
//            break;
//        }
//        cout << countGoodNumbers(L, R) << endl;
//    }
//    return 0;
//}
