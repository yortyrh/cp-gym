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

    explicit DSU(int n) : parent(n + 1), sz(n + 1, 1) { iota(parent.begin(), parent.end(), 0); }

    int find(int v) {
        if (parent[v] != v) {
            parent[v] = find(parent[v]);
        }
        return parent[v];
    }

    bool unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) {
            return false;
        }
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        return true;
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    sort(edges.begin(), edges.end(),
         [](const array<int, 3>& a, const array<int, 3>& b) { return a[2] < b[2]; });
    DSU dsu(n);
    int total = 0;
    int taken = 0;
    for (auto [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            total += w;
            ++taken;
        }
    }
    if (n > 0 && taken != n - 1) {
        cout << -1 << '\n';
    } else {
        cout << total << '\n';
    }
    return 0;
}
