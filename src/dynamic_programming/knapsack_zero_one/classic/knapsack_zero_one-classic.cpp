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
    int n, capacity;
    cin >> n >> capacity;
    vector<int> dp(capacity + 1);
    for (int i = 0; i < n; ++i) {
        int weight, value;
        cin >> weight >> value;
        if (weight > capacity) {
            continue;
        }
        for (int current = capacity; current >= weight; --current) {
            dp[current] = max(dp[current], dp[current - weight] + value);
        }
    }
    cout << dp[capacity] << '\n';
    return 0;
}
