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
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    const int inf = 4e18;
    vector<int> dp(amount + 1, inf);
    dp[0] = 0;
    for (int coin : coins) {
        for (int value = coin; value <= amount; ++value) {
            if (dp[value - coin] != inf) {
                dp[value] = min(dp[value], dp[value - coin] + 1);
            }
        }
    }
    if (dp[amount] == inf) {
        cout << -1 << '\n';
    } else {
        cout << dp[amount] << '\n';
    }
    return 0;
}
