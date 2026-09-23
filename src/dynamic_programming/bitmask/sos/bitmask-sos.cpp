#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

signed main() {
    int n;
    cin >> n;
    int full = 1 << n;
    vector<int> dp(full);
    for (int i = 0; i < full; ++i) {
        cin >> dp[i];
    }
    for (int bit = 0; bit < n; ++bit) {
        for (int mask = 0; mask < full; ++mask) {
            if (mask & (1 << bit)) {
                dp[mask] += dp[mask ^ (1 << bit)];
            }
        }
    }
    for (int i = 0; i < full; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << dp[i];
    }
    cout << '\n';
    return 0;
}
