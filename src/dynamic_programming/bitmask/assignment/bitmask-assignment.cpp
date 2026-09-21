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

const int MOD = 1000000007;

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> allowed(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> allowed[i][j];
        }
    }
    int full = 1 << n;
    vector<int> dp(full);
    dp[0] = 1;
    for (int mask = 0; mask < full; ++mask) {
        int person = __builtin_popcountll(mask);
        if (person >= n) {
            continue;
        }
        for (int job = 0; job < n; ++job) {
            if ((mask & (1 << job)) == 0 && allowed[person][job]) {
                int next_mask = mask | (1 << job);
                dp[next_mask] += dp[mask];
                if (dp[next_mask] >= MOD) {
                    dp[next_mask] -= MOD;
                }
            }
        }
    }
    cout << dp[full - 1] << '\n';
    return 0;
}
