#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];

    sort(A.begin(), A.end());

    int i = 0, ans = 0;

    for (int j = 0; j < N; j++) {
        while (A[j] - A[i] > 10) {
            i++;
        }
        ans = max(ans, j - i + 1);
    }

    cout << ans;
    return 0;
}