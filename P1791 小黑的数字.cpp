////#include<iostream>
////using namespace std;
////bool ShenPan(long long int n) {
////    int a;
////    while (n != 0) {
////        a = n % 10;
////        n = n / 10;
////        if (a == 4)
////            return false;
////        if (a == 2) {
////            a = n % 10;
////            if (a == 6)
////                return false;
////        }
////    }
////    return true;
////}
////int main() {
////    long long int L, R;
////    int answer;
////    cin >> L >> R;
////
////    while (L != 0 && R != 0) {
////
////        for (int i = L; i <= R; i++) {
////            if (ShenPan(i))
////                answer++;
////        }
////
////        cout << answer << endl;
////
////        cin >> L >> R;
////        answer = 0;
////    }
////    return 0;
////}
//#include<iostream>
//using namespace std;
//bool is_bad(int x) {
//	int k;
//	
//	while (x != 0) {
//		k = x % 10;
//		if (k == 4)
//			return true;
//		if (k == 2) {
//			k = x / 10;
//			k = k % 10;
//			if (k == 6)
//			{
//				return true;
//			}
//		}
//		x = x / 10;
//	}
//	
//	return false;
//}
//int main() {
//	int L=0, R=0;
//	
//	while(true) {
//		int num = 0;
//		cin >> L>> R;
//		if (L == 0 && R == 0)
//			break;
//		for (int i = L; i <= R; i++) {
//			if (!is_bad(i))
//				num++;
//		}
//		cout << num << endl;
//	} 
//	
//
//}
