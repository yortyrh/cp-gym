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

struct SegTree {
    int n;
    vector<int> tree;
    explicit SegTree(int n) : n(n), tree(2 * n) {}

    void build() {
        for (int i = n - 1; i > 0; --i) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    void set(int i, int v) {
        i += n;
        tree[i] = v;
        for (i >>= 1; i > 0; i >>= 1) {
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        }
    }

    int range_sum(int l, int r) {
        int result = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                result += tree[l++];
            }
            if (r & 1) {
                result += tree[--r];
            }
        }
        return result;
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    SegTree tree(n);
    for (int i = 0; i < n; ++i) {
        cin >> tree.tree[n + i];
    }
    tree.build();
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, v;
            cin >> i >> v;
            tree.set(i - 1, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << tree.range_sum(l - 1, r) << '\n';
        }
    }
    return 0;
}
