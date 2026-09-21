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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }
    auto w = [&](int l, int r) {
        return pref[r + 1] - pref[l];
    };
    const int inf = 4e18;
    vector<vector<int>> dp(n, vector<int>(n));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        opt[i][i] = i;
    }
    for (int len = 2; len <= n; ++len) {
        for (int l = 0; l + len - 1 < n; ++l) {
            int r = l + len - 1;
            int lo = opt[l][r - 1];
            int hi = opt[l + 1][r];
            if (hi >= r) {
                hi = r - 1;
            }
            dp[l][r] = inf;
            for (int mid = lo; mid <= hi; ++mid) {
                int val = dp[l][mid] + dp[mid + 1][r] + w(l, r);
                if (val < dp[l][r]) {
                    dp[l][r] = val;
                    opt[l][r] = mid;
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}
