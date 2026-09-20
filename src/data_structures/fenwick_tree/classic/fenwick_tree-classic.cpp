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

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }

    int range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    Fenwick tree(n);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tree.add(i, a[i]);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            tree.add(i, v - a[i]);
            a[i] = v;
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
