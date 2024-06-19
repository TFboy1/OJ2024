//
//#include<iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int main() {
//	int n, m;
//	int x;
//	int time=0;
//	cin >> n >> m;
//	queue<int> v;
//	vector<int> water;
//	for (int i = 0; i < n; i++) {
//		cin >> x;
//		v.push(x);
//	}
//	for (int i = 0; i < m; i++) {
//			water.push_back(v.front());
//			v.pop();
//	}
//
//	while (!v.empty()) {
//		int k = 0;
//		int min=water[0];
//		for (int i = 0; i < water.size(); i++) {
//			if (water[i] < min) {
//				min= water[i];
//			}
//		}
//			for (int i = 0; i < water.size(); i++) {
//				water[i] = water[i] - min;
//			}
//			time = time + min;
//			for (int i = 0; i < water.size(); i++) {
//			if(water[i]==0){
//				water[i] = v.front();
//				v.pop();
//				break;
//			}		
//			}
//			
//		}
//	int max = 0;
//	for (int i = 0; i < water.size(); i++) {
//		if (water[i] > max) {
//			max = water[i];
//		}
//	}
//	cout << time + max<<endl;
//}
//	
