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

struct LazySegTree {
    int n;
    vector<int> tree, lazy;

    explicit LazySegTree(int n) : n(n), tree(4 * n), lazy(4 * n) {}

    void apply(int v, int len, int add) {
        tree[v] += add * len;
        lazy[v] += add;
    }

    void push(int v, int tl, int tr) {
        if (lazy[v] == 0 || tl == tr) {
            return;
        }
        int tm = (tl + tr) / 2;
        apply(v * 2, tm - tl + 1, lazy[v]);
        apply(v * 2 + 1, tr - tm, lazy[v]);
        lazy[v] = 0;
    }

    void build(int v, int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            tree[v] = a[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, a);
        build(v * 2 + 1, tm + 1, tr, a);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

    void range_add(int v, int tl, int tr, int l, int r, int add) {
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            apply(v, tr - tl + 1, add);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        range_add(v * 2, tl, tm, l, min(r, tm), add);
        range_add(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
        tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }

    int range_sum(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return range_sum(v * 2, tl, tm, l, min(r, tm)) +
               range_sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    LazySegTree tree(n);
    tree.build(1, 1, n, a);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.range_add(1, 1, n, l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(1, 1, n, l, r) << '\n';
        }
    }
    return 0;
}
