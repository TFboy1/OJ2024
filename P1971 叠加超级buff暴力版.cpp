//#include<iostream>
//#include<vector>
//#include<cmath>
//
//using namespace std;
//
//int countDigits(int number) {
//    return number == 0 ? 1 : (int)log10(abs(number)) + 1;
//}
//int getHP(int HP) {
//    return pow(10, HP);
//}
//void calculate_Buff(int X, int HP) {
//    int buffCount = 1;
//    int ATK = X;
//    int digital = 0;
//    while (countDigits(ATK) <= HP) {
//        if (buffCount % 2 == 0 && buffCount != 0) {
//            ATK *= buffCount;
//        }
//        ATK *= X;
//        digital = log10(ATK) + 1;
//        buffCount++;
//    }
//    cout << --buffCount << endl;
//}
//
//int main() {
//    int X, N;
//    cin >> X >> N;
//    int HP[1000];
//    for (int i = 0; i < N; i++) {
//        cin >> HP[i];
//    }
//
//    for (int i = 0; i < N; i++) {
//        calculate_Buff(X, HP[i]);
//    }
//    return 0;
//}
// 
