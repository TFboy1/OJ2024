//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int countSafeFishSizes(int minSize, int maxSize, int n, vector<int>& fishSizes) {
//    int count = 0;
//
//    for (int newFishSize = minSize; newFishSize <= maxSize; ++newFishSize) {
//        bool isSafe = true;
//        for (int existingFishSize : fishSizes) {
//            if (2 * existingFishSize <= newFishSize && newFishSize <= 10 * existingFishSize) {
//                isSafe = false;
//                break;
//            }
//            if (existingFishSize <= 10 * newFishSize && newFishSize <= existingFishSize / 2) {
//                isSafe = false;
//                break;
//            }
//        }
//        if (isSafe) {
//            count++;
//        }
//    }
//
//    return count;
//}
//
//int main() {
//    int minSize, maxSize, n;
//    cin >> minSize >> maxSize;
//    cin >> n;
//    vector<int> fishSizes(n);
//    for (int i = 0; i < n; ++i) {
//        cin >> fishSizes[i];
//    }
//
//    cout << countSafeFishSizes(minSize, maxSize, n, fishSizes) << endl;
//
//    return 0;
//}
