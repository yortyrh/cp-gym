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
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> dist[i][j];
        }
    }
    int full = 1 << n;
    const int inf = 4e18;
    vector<vector<int>> dp(full, vector<int>(n, inf));
    dp[1][0] = 0;
    for (int mask = 1; mask < full; ++mask) {
        for (int last = 0; last < n; ++last) {
            if (dp[mask][last] == inf) {
                continue;
            }
            for (int next = 0; next < n; ++next) {
                if (mask & (1 << next)) {
                    continue;
                }
                int next_mask = mask | (1 << next);
                dp[next_mask][next] = min(dp[next_mask][next], dp[mask][last] + dist[last][next]);
            }
        }
    }
    int answer = inf;
    for (int last = 0; last < n; ++last) {
        if (dp[full - 1][last] != inf) {
            answer = min(answer, dp[full - 1][last] + dist[last][0]);
        }
    }
    cout << answer << '\n';
    return 0;
}
