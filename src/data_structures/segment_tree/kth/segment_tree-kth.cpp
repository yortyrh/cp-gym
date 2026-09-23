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

struct ValueSegTree {
    int sz;
    vector<int> vals;
    vector<vector<int>> tree;

    explicit ValueSegTree(const vector<int>& a) {
        vals.assign(a.begin() + 1, a.end());
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        sz = vals.size();
        tree.assign(4 * sz, {});
        vector<vector<int>> buckets(sz);
        int n = a.size() - 1;
        for (int i = 1; i <= n; ++i) {
            int rank = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
            buckets[rank].push_back(i);
        }
        build(1, 0, sz - 1, buckets);
    }

    void build(int v, int tl, int tr, const vector<vector<int>>& buckets) {
        if (tl == tr) {
            tree[v] = buckets[tl];
            return;
        }
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm, buckets);
        build(v * 2 + 1, tm + 1, tr, buckets);
        tree[v].resize(tree[v * 2].size() + tree[v * 2 + 1].size());
        merge(tree[v * 2].begin(), tree[v * 2].end(), tree[v * 2 + 1].begin(), tree[v * 2 + 1].end(),
              tree[v].begin());
    }

    int count_in(int v, int l, int r) {
        const vector<int>& pos = tree[v];
        return upper_bound(pos.begin(), pos.end(), r) - lower_bound(pos.begin(), pos.end(), l);
    }

    int kth(int v, int tl, int tr, int l, int r, int k) {
        if (tl == tr) {
            return vals[tl];
        }
        int tm = (tl + tr) / 2;
        int left_count = count_in(v * 2, l, r);
        if (k <= left_count) {
            return kth(v * 2, tl, tm, l, r, k);
        }
        return kth(v * 2 + 1, tm + 1, tr, l, r, k - left_count);
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    ValueSegTree tree(a);
    while (q--) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << tree.kth(1, 0, tree.sz - 1, l, r, k) << '\n';
    }
    return 0;
}
