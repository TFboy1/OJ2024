//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//// ����һ���ṹ�����洢ÿ�ѽ�ҵ���Ϣ
//struct Gold {
//    int weight;
//    int value;
//    double unit_value; // ��λ��ֵ
//};
//
//// ����λ��ֵ�Ӵ�С����
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
//    // ����λ��ֵ�Ӵ�С����
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
//            // ������ȫװ�뱳��
//            max_value += golds[i].value;
//            remaining_capacity -= golds[i].weight;
//        }
//        else {
//            // ֻ��װ�벿�ֽ��
//            max_value += golds[i].unit_value * remaining_capacity;
//            remaining_capacity = 0;
//        }
//    }
//
//    cout << (int)max_value << endl;
//
//    return 0;
//}
