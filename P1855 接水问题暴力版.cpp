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
//    int q[50]; // ʹ������������� q
//    int v[50]; // ʹ������������� v
//
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//
//    for (int i = 0; i < m; i++) {
//        q[i] = v[i];
//    }
//
//    sort(q, q + m); // ������ q ��������
//
//    int time = 0;
//    int t = 0;
//    int i = m; // ��ʼ�� i Ϊ m
//
//    while (m > 0) { // �޸�ѭ������Ϊ m > 0���� q ��Ϊ��
//        t = q[0]; // ÿ�β��������㵱ǰ���еĵ�һ��Ԫ���� t �Ĳ�ֵ
//        int j;
//        for (j = 0; j < m - 1; j++) {
//            q[j] = q[j + 1]; // �������е�Ԫ������һλ
//        }
//        q[j]= 0; // �������е����һ��Ԫ����Ϊ 0
//        m--; // ���¶��д�С
//        int k = m;
//        for (int j = 0; j < k; j++) {
//            q[j] = q[j] - t; // ���¶����е�Ԫ��
//            if(q[j] == 0) m--; 
//        }
//
//        time += t;
//
//        if (i < n) {
//           
//            q[m] = v[i]; // �� v �е���һ��Ԫ����ӵ�����ĩβ          
//            sort(q, q + m + 1); // �԰�����Ԫ�ص�����������
//            i++;
//            m++; // ���¶��д�С
//        }
//    }
//
//    cout << time << endl;
//
//    return 0;
//}
