//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// 定义一个结构体来存储每堆金币的信息
//struct Gold {
//    int weight;
//    int value;
//    double unit_value; // 单位价值
//};
//
//// 按单位价值从大到小排序
//bool compare(Gold a, Gold b) {
//    return a.unit_value > b.unit_value;
//}
//
//int main() {
//    int N, T;
//    cin >> N >> T;
//    vector<Gold> golds(N);
//
//    for (int i = 0; i < N; i++) {
//        cin >> golds[i].weight >> golds[i].value;
//        golds[i].unit_value = (double)golds[i].value / golds[i].weight;
//    }
//
//    // 按单位价值从大到小排序
//    sort(golds.begin(), golds.end(), compare);
//
//    double max_value = 0.0;
//    int remaining_capacity = T;
//
//    for (int i = 0; i < N; i++) {
//        if (remaining_capacity == 0) {
//            break;
//        }
//        if (golds[i].weight <= remaining_capacity) {
//            // 可以完全装入背包
//            max_value += golds[i].value;
//            remaining_capacity -= golds[i].weight;
//        }
//        else {
//            // 只能装入部分金币
//            max_value += golds[i].unit_value * remaining_capacity;
//            remaining_capacity = 0;
//        }
//    }
//
//    cout << (int)max_value << endl;
//
//    return 0;
//}
