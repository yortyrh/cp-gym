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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }
    const int mod = 1e9 + 7;
    vector<vector<int>> dp(n, vector<int>(m));
    if (grid[0][0] != '#') {
        dp[0][0] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '#') {
                continue;
            }
            if (i) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
            }
            if (j) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
        }
    }
    cout << dp[n - 1][m - 1] << '\n';
    return 0;
}
