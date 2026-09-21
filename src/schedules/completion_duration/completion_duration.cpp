#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};
static FastIO fastio;

signed main() {
    int n;
    cin >> n;
    vector<int> durations(n), order(n);
    for (int i = 0; i < n; ++i) {
        cin >> durations[i];
        order[i] = i;
    }
    sort(order.begin(), order.end(), [&](int lhs, int rhs) {
        if (durations[lhs] != durations[rhs]) {
            return durations[lhs] < durations[rhs];
        }
        return lhs < rhs;
    });
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << order[i];
    }
    cout << '\n';
    return 0;
}
