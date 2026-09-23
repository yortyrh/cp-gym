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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int mid = n / 2;
    vector<int> left_sums;
    vector<int> right_sums;
    int left_n = mid;
    int right_n = n - mid;
    int left_tot = 1 << left_n;
    for (int mask = 0; mask < left_tot; ++mask) {
        int s = 0;
        for (int i = 0; i < left_n; ++i) {
            if ((mask >> i) & 1) {
                s += a[i];
            }
        }
        left_sums.push_back(s);
    }
    int right_tot = 1 << right_n;
    for (int mask = 0; mask < right_tot; ++mask) {
        int s = 0;
        for (int i = 0; i < right_n; ++i) {
            if ((mask >> i) & 1) {
                s += a[mid + i];
            }
        }
        right_sums.push_back(s);
    }
    sort(right_sums.begin(), right_sums.end());
    int ans = 0;
    for (int s : left_sums) {
        int need = x - s;
        auto lo = lower_bound(right_sums.begin(), right_sums.end(), need);
        auto hi = upper_bound(right_sums.begin(), right_sums.end(), need);
        ans += hi - lo;
    }
    cout << ans << '\n';
    return 0;
}
