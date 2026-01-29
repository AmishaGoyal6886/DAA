#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<double, double>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double minDist = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dx = points[i].first - points[j].first;
            double dy = points[i].second - points[j].second;
            double dist = sqrt(dx * dx + dy * dy);
            minDist = min(minDist, dist);
        }
    }

    cout << minDist;
    return 0;
}