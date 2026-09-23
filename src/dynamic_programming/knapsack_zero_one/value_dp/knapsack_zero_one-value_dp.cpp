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
    vector<int> weight(n), value(n);
    int sum_value = 0;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
        sum_value += value[i];
    }
    const int inf = 4e18;
    vector<int> dp(sum_value + 1, inf);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int current = sum_value; current >= value[i]; --current) {
            if (dp[current - value[i]] != inf) {
                dp[current] = min(dp[current], dp[current - value[i]] + weight[i]);
            }
        }
    }
    int answer = 0;
    for (int current = 0; current <= sum_value; ++current) {
        if (dp[current] <= capacity) {
            answer = current;
        }
    }
    cout << answer << '\n';
    return 0;
}
