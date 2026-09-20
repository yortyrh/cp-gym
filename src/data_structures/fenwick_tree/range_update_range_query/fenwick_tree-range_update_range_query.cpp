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
};

struct RangeFenwick {
    int n;
    Fenwick b1, b2;
    explicit RangeFenwick(int n) : n(n), b1(n), b2(n) {}

    void range_add(int l, int r, int v) {
        b1.add(l, v);
        b2.add(l, v * (l - 1));
        if (r + 1 <= n) {
            b1.add(r + 1, -v);
            b2.add(r + 1, -v * r);
        }
    }

    int prefix(int i) { return b1.prefix_sum(i) * i - b2.prefix_sum(i); }

    int range_sum(int l, int r) { return prefix(r) - prefix(l - 1); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    RangeFenwick tree(n);
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        tree.range_add(i, i, value);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.range_add(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l, r) << '\n';
        }
    }
    return 0;
}
