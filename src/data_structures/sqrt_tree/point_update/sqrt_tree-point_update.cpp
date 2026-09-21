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

const int inf = 4e18;

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
    vector<int> block_min(blocks, inf);
    auto rebuild = [&](int block) {
        int begin = block * B + 1;
        int end = min(n, begin + B - 1);
        int best = inf;
        for (int i = begin; i <= end; ++i) {
            best = min(best, a[i]);
        }
        block_min[block] = best;
    };
    for (int block = 0; block < blocks; ++block) {
        rebuild(block);
    }
    auto range_min = [&](int l, int r) {
        int result = inf;
        while (l <= r && (l - 1) % B != 0) {
            result = min(result, a[l]);
            ++l;
        }
        while (l + B - 1 <= r) {
            result = min(result, block_min[(l - 1) / B]);
            l += B;
        }
        while (l <= r) {
            result = min(result, a[l]);
            ++l;
        }
        return result;
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            a[i] = v;
            rebuild((i - 1) / B);
        } else {
            int l, r;
            cin >> l >> r;
            cout << range_min(l, r) << '\n';
        }
    }
    return 0;
}
