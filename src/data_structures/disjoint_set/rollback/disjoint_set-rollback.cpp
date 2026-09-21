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

struct DSU {
    vector<int> parent, sz;
    vector<pair<int, int>> history;

    explicit DSU(int n) : parent(n + 1), sz(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        while (parent[v] != v) {
            v = parent[v];
        }
        return v;
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        history.push_back({b, a});
    }

    void rollback() {
        if (history.empty()) {
            return;
        }
        auto [child, root] = history.back();
        history.pop_back();
        parent[child] = child;
        sz[root] -= sz[child];
    }

    bool same(int a, int b) { return find(a) == find(b); }
};

signed main() {
    int n, q;
    cin >> n >> q;
    DSU dsu(n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int a, b;
            cin >> a >> b;
            dsu.unite(a, b);
        } else if (type == 2) {
            int a, b;
            cin >> a >> b;
            cout << (dsu.same(a, b) ? "YES\n" : "NO\n");
        } else {
            dsu.rollback();
        }
    }
    return 0;
}
