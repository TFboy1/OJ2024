//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 比较函数，用于对电池按使用时间排序
//bool compare(int a, int b) {
//    return a < b;
//}
//
//int main() {
//    int n;
//    while (cin >> n) {
//        vector<int> batteries(n);
//        for (int i = 0; i < n; ++i) {
//            cin >> batteries[i];
//        }
//        sort(batteries.begin(), batteries.end(), compare);
//
//        int total_time = 0;
//        int i = 0;
//        int j = n - 1;
//        while (i <= j) {
//            if (i == j) {
//                total_time += batteries[i];
//                break;
//            }
//            int time = min(batteries[i], batteries[j]);
//            total_time += time;
//            batteries[i] -= time;
//            batteries[j] -= time;
//            if (batteries[i] == 0) {
//                i++;
//            }
//            if (batteries[j] == 0) {
//                j--;
//            }
//        }
//
//        cout << total_time << endl;
//    }
//    return 0;
//}
