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
    int n, amount;
    cin >> n >> amount;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }
    const int mod = 1000000007;
    vector<int> ways(amount + 1);
    ways[0] = 1;
    for (int coin : coins) {
        for (int value = coin; value <= amount; ++value) {
            ways[value] += ways[value - coin];
            if (ways[value] >= mod) {
                ways[value] -= mod;
            }
        }
    }
    cout << ways[amount] << '\n';
    return 0;
}
