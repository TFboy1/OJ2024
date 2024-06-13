#include<iostream>
using namespace std;
bool ShenPan(long long int n) {
    int a;
    while (n != 0) {
        a = n % 10;
        n = n / 10;
        if (a == 4)
            return false;
        if (a == 2) {
            a = n % 10;
            if (a == 6)
                return false;
        }
    }
    return true;
}
int main() {
    long long int L, R;
    int answer;
    cin >> L >> R;

    while (L != 0 && R != 0) {

        for (int i = L; i <= R; i++) {
            if (ShenPan(i))
                answer++;
        }

        cout << answer << endl;

        cin >> L >> R;
        answer = 0;
    }
    return 0;
}
