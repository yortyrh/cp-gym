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
    vector<int> parent, sz, parity;
    bool bipartite = true;

    explicit DSU(int n) : parent(n + 1), sz(n + 1, 1), parity(n + 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        if (parent[v] == v) {
            return v;
        }
        int u = parent[v];
        parent[v] = find(u);
        parity[v] ^= parity[u];
        return parent[v];
    }

    void add_edge(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        int xa = parity[a];
        int xb = parity[b];
        if (pa == pb) {
            if (xa == xb) {
                bipartite = false;
            }
            return;
        }
        if (sz[pa] < sz[pb]) {
            swap(pa, pb);
            swap(xa, xb);
        }
        parent[pb] = pa;
        parity[pb] = xa ^ xb ^ 1;
        sz[pa] += sz[pb];
    }
};

signed main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        dsu.add_edge(u, v);
        cout << (dsu.bipartite ? "YES\n" : "NO\n");
    }
    return 0;
}
