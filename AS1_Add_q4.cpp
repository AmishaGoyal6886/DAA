#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
        v.push_back({a[i], i});

    sort(v.begin(), v.end(), greater<>());

    set<int> pos;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int value = v[i].first;
        int index = v[i].second;

        pos.insert(index);

        auto it = pos.find(index);

        int left = 0, right = 0;

        auto l = it;
        while (l != pos.begin() && left <= k) {
            --l;
            left++;
        }

        auto r = it;
        while (++r != pos.end() && right <= k) {
            right++;
        }

        if (left + right >= k)
            sum += value;
    }

    cout << sum;
    return 0;
}