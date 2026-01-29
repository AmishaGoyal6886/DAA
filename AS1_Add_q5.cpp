#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        long long N, H, W;
        cin >> N >> H >> W;

        long long low = 0, high = 1;
        
        while ((high / W) * (high / H) < N)
            high *= 2;

        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;

            if ((mid / W) * (mid / H) >= N) {
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