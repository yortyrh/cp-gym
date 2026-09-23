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
    int n, min_length;
    cin >> n >> min_length;
    vector<double> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    double low = values[0];
    double high = values[0];
    for (int i = 0; i < n; ++i) {
        low = min(low, values[i]);
        high = max(high, values[i]);
    }
    auto feasible = [&](double average) {
        vector<double> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + values[i] - average;
        }
        double min_prefix = 0.0;
        for (int end = min_length; end <= n; ++end) {
            min_prefix = min(min_prefix, prefix[end - min_length]);
            if (prefix[end] >= min_prefix) {
                return true;
            }
        }
        return false;
    };
    for (int iteration = 0; iteration < 80; ++iteration) {
        double middle = (low + high) / 2.0;
        if (feasible(middle)) {
            low = middle;
        } else {
            high = middle;
        }
    }
    cout << fixed << setprecision(10) << low << '\n';
    return 0;
}
