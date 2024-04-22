//¶¯Ì¬¹æ»®


//#include<iostream>
//#include<algorithm>
//using namespace std;
//class Node {
//public:
//	int value;
//	int num;
//	int time;
//	int cost;
//};
//int get_most(int x,int n,Node values[],int Max_ti) {
//	int sum=0;
//	for (int i = 0; i < n; i++) {
//		
//		/*if (Max_ti <= 0) {
//			break;
//		}
//		if (Max_ti >= values[i].time) {
//			sum+=values[i].cost;
//			Max_ti -= values[i].time;
//			values[i].num = 1;
//		}*/
//	}
//}
//int main() {
//	int m,n;
//	Node values[1000];
//	
//	cin >> m >> n;
//
//	for (int i = 0; i < n; i++) {
//		cin >> values[i].time;
//	}
//	for (int i = 0; i < n; i++) {
//		cin >> values[i].cost;
//	}
//	for (int i = 0; i < n; i++) {
//		values[i].value =1.0*values[i].cost/values[i].time;
//		values[i].num = 0;
//	}
//	int MAX_ti = n + 10;
//	sort(values, values + n, [](Node a, Node b) {
//		return a.value > b.value;
//	});
//	double sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (MAX_ti <= 0) {
//			break;
//		}
//		if (MAX_ti >= values[i].time) {
//			
//			MAX_ti -=values[i].time;
//			values[i].num = 1;
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		if (values[i].num == 0) {
//			sum += values[i].cost;
//		}
//	}
//	cout << m-sum << endl;
//}

