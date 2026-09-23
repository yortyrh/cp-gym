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

const int MOD = 1000000007;

signed main() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adj[i][j];
        }
    }
    int full = 1 << n;
    vector<vector<int>> dp(full, vector<int>(n));
    for (int start = 0; start < n; ++start) {
        dp[1 << start][start] = 1;
    }
    for (int mask = 1; mask < full; ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] == 0) {
                continue;
            }
            for (int next = 0; next < n; ++next) {
                if ((mask & (1 << next)) || adj[last][next] == 0) {
                    continue;
                }
                int next_mask = mask | (1 << next);
                dp[next_mask][next] += dp[mask][last];
                if (dp[next_mask][next] >= MOD) {
                    dp[next_mask][next] -= MOD;
                }
            }
        }
    }
    int answer = 0;
    for (int last = 0; last < n; ++last) {
        answer += dp[full - 1][last];
        if (answer >= MOD) {
            answer -= MOD;
        }
    }
    cout << answer << '\n';
    return 0;
}
