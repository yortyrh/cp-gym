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
    vector<array<int, 4>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        edges[i][3] = i;
    }
    sort(edges.begin(), edges.end(),
         [](const array<int, 4>& a, const array<int, 4>& b) { return a[2] < b[2]; });
    DSU dsu(n);
    vector<char> used(m, 0);
    vector<vector<pair<int, int>>> tree(n + 1);
    int best = 0;
    int taken = 0;
    for (auto [u, v, w, idx] : edges) {
        if (dsu.unite(u, v)) {
            used[idx] = 1;
            best += w;
            ++taken;
            tree[u].push_back({v, w});
            tree[v].push_back({u, w});
        }
    }
    if (n == 0 || taken != n - 1) {
        cout << -1 << '\n';
        return 0;
    }
    int LOG = 1;
    while ((1 << LOG) <= n) {
        ++LOG;
    }
    vector<int> depth(n + 1);
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    vector<vector<int>> mx(LOG, vector<int>(n + 1));
    auto dfs = [&](auto&& self, int v, int p) -> void {
        for (auto [to, w] : tree[v]) {
            if (to == p) {
                continue;
            }
            depth[to] = depth[v] + 1;
            up[0][to] = v;
            mx[0][to] = w;
            self(self, to, v);
        }
    };
    dfs(dfs, 1, 0);
    for (int k = 1; k < LOG; ++k) {
        for (int v = 1; v <= n; ++v) {
            int mid = up[k - 1][v];
            up[k][v] = up[k - 1][mid];
            mx[k][v] = max(mx[k - 1][v], mx[k - 1][mid]);
        }
    }
    auto max_on_path = [&](int a, int b) {
        const int neg_inf = -4e18;
        int heaviest = neg_inf;
        if (depth[a] < depth[b]) {
            swap(a, b);
        }
        int diff = depth[a] - depth[b];
        for (int k = 0; k < LOG; ++k) {
            if (diff & (1 << k)) {
                heaviest = max(heaviest, mx[k][a]);
                a = up[k][a];
            }
        }
        if (a == b) {
            return heaviest;
        }
        for (int k = LOG - 1; k >= 0; --k) {
            if (up[k][a] != up[k][b]) {
                heaviest = max(heaviest, mx[k][a]);
                heaviest = max(heaviest, mx[k][b]);
                a = up[k][a];
                b = up[k][b];
            }
        }
        heaviest = max(heaviest, mx[0][a]);
        heaviest = max(heaviest, mx[0][b]);
        return heaviest;
    };
    const int inf = 4e18;
    int second = inf;
    for (auto [u, v, w, idx] : edges) {
        if (used[idx] != 0) {
            continue;
        }
        int replacement = best - max_on_path(u, v) + w;
        if (replacement > best) {
            second = min(second, replacement);
        }
    }
    if (second == inf) {
        cout << -1 << '\n';
    } else {
        cout << second << '\n';
    }
    return 0;
}
