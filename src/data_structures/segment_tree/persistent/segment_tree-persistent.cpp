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

struct Node {
    int left, right, sum;
};

struct PersistentSegTree {
    int n;
    vector<Node> nodes;
    vector<int> root;

    explicit PersistentSegTree(int n) : n(n) {
        nodes.reserve(4 * n + 25 * 200000);
        nodes.push_back({-1, -1, 0});
    }

    int make_node(int left, int right, int sum) {
        nodes.push_back({left, right, sum});
        return nodes.size() - 1;
    }

    int build(int tl, int tr, const vector<int>& a) {
        if (tl == tr) {
            return make_node(-1, -1, a[tl]);
        }
        int tm = (tl + tr) / 2;
        int left = build(tl, tm, a);
        int right = build(tm + 1, tr, a);
        return make_node(left, right, nodes[left].sum + nodes[right].sum);
    }

    int update(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            return make_node(-1, -1, value);
        }
        int tm = (tl + tr) / 2;
        int left = nodes[v].left;
        int right = nodes[v].right;
        if (pos <= tm) {
            left = update(left, tl, tm, pos, value);
        } else {
            right = update(right, tm + 1, tr, pos, value);
        }
        return make_node(left, right, nodes[left].sum + nodes[right].sum);
    }

    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return nodes[v].sum;
        }
        int tm = (tl + tr) / 2;
        return query(nodes[v].left, tl, tm, l, min(r, tm)) +
               query(nodes[v].right, tm + 1, tr, max(l, tm + 1), r);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    PersistentSegTree tree(n);
    tree.root.push_back(tree.build(1, n, a));
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int k, i, v;
            cin >> k >> i >> v;
            tree.root.push_back(tree.update(tree.root[k], 1, n, i, v));
        } else {
            int k, l, r;
            cin >> k >> l >> r;
            cout << tree.query(tree.root[k], 1, n, l, r) << '\n';
        }
    }
    return 0;
}
