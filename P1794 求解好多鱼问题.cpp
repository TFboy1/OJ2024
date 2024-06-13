//#include<iostream>
//using namespace std;
//
//bool can_eat(int fishSize[], int size, int n) {
//	for (int i = 0; i < n; i++) {
//		if ((1.0*size / fishSize[i] >= 2 && 1.0 * size / fishSize[i] <= 10) || (1.0 * fishSize[i] / size >= 2 && 1.0 * fishSize[i] / size <= 10)) {
//						return true;
//		}
//	}
//	return false;
//}
//
//int main() {
//	int minSize, maxSize;
//	int n, fishSize[1000];
//	cin>> minSize >> maxSize;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> fishSize[i];
//	}
//	int k = 0;
//	for (int i = minSize; i <= maxSize; i++) {
//		if (can_eat(fishSize, i, n)) {
//			continue;
//		}
//		else {
//			k++;
//		}
//	}
//	cout << k;
//}