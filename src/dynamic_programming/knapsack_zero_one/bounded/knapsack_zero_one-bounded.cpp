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
    vector<int> item_weight, item_value;
    for (int i = 0; i < n; ++i) {
        int weight, value, count;
        cin >> weight >> value >> count;
        int take = 1;
        while (count > 0) {
            int chunk = min(take, count);
            item_weight.push_back(weight * chunk);
            item_value.push_back(value * chunk);
            count -= chunk;
            take *= 2;
        }
    }
    vector<int> dp(capacity + 1);
    int item_count = item_weight.size();
    for (int i = 0; i < item_count; ++i) {
        int weight = item_weight[i];
        int value = item_value[i];
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
