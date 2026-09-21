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
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int B = 1;
    while (B * B < n) {
        ++B;
    }
    int blocks = (n + B - 1) / B;
    vector<int> block_sum(blocks);
    for (int i = 1; i <= n; ++i) {
        block_sum[(i - 1) / B] += a[i];
    }
    auto range_sum = [&](int l, int r) {
        int total = 0;
        while (l <= r && (l - 1) % B != 0) {
            total += a[l];
            ++l;
        }
        while (l + B - 1 <= r) {
            total += block_sum[(l - 1) / B];
            l += B;
        }
        while (l <= r) {
            total += a[l];
            ++l;
        }
        return total;
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            a[i] += v;
            block_sum[(i - 1) / B] += v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << range_sum(l, r) << '\n';
        }
    }
    return 0;
}
