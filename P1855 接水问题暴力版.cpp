//
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//
//    int q[50]; // 使用数组代替向量 q
//    int v[50]; // 使用数组代替向量 v
//
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//
//    for (int i = 0; i < m; i++) {
//        q[i] = v[i];
//    }
//
//    sort(q, q + m); // 对数组 q 进行排序
//
//    int time = 0;
//    int t = 0;
//    int i = m; // 初始化 i 为 m
//
//    while (m > 0) { // 修改循环条件为 m > 0，即 q 不为空
//        t = q[0]; // 每次操作，计算当前队列的第一个元素与 t 的差值
//        int j;
//        for (j = 0; j < m - 1; j++) {
//            q[j] = q[j + 1]; // 将队列中的元素左移一位
//        }
//        q[j]= 0; // 将队列中的最后一个元素置为 0
//        m--; // 更新队列大小
//        int k = m;
//        for (int j = 0; j < k; j++) {
//            q[j] = q[j] - t; // 更新队列中的元素
//            if(q[j] == 0) m--; 
//        }
//
//        time += t;
//
//        if (i < n) {
//           
//            q[m] = v[i]; // 将 v 中的下一个元素添加到队列末尾          
//            sort(q, q + m + 1); // 对包含新元素的子数组排序
//            i++;
//            m++; // 更新队列大小
//        }
//    }
//
//    cout << time << endl;
//
//    return 0;
//}
