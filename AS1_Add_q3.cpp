#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        long long max1 = 0, max2 = 0;
        for (int i = 0; i < N; i++) {
            long long x;
            cin >> x;

            if (x > max1) {
                max2 = max1;
                max1 = x;
            } else if (x > max2) {
                max2 = x;
            }
        }

        cout << max1 + max2 << endl;
    }

    return 0;
}