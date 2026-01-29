#include <iostream>
#include <vector>
using namespace std;

bool possible(vector<int>& a, int n, int m, int x) {
    int parts = 1;
    int curr = 0;

    for (int i = 0; i < n; i++) {
        if ((curr | a[i]) <= x) {
            curr |= a[i];
        } else {
            parts++;
            curr = a[i];
        }
    }

    return parts <= m;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<int> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int low = 0, high = 0;
        for (int i = 0; i < N; i++) {
            low = max(low, A[i]);
            high |= A[i];
        }

        int ans = high;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (possible(A, N, M, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}