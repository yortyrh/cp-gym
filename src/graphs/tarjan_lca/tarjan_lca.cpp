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

    explicit DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int v) {
        while (v != parent[v]) {
            parent[v] = parent[parent[v]];
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
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        queries[i] = {u, v};
    }
    vector<vector<pair<int, int>>> by_vertex(n);
    for (int index = 0; index < q; ++index) {
        by_vertex[queries[index].first].push_back({queries[index].second, index});
        by_vertex[queries[index].second].push_back({queries[index].first, index});
    }
    DSU dsu(n);
    vector<int> ancestor(n);
    vector<char> visited(n, 0);
    vector<int> answer(q, 0);
    for (int vertex = 0; vertex < n; ++vertex) {
        ancestor[vertex] = vertex;
    }
    auto dfs = [&](auto&& self, int vertex, int parent) -> void {
        visited[vertex] = 1;
        ancestor[vertex] = vertex;
        for (int child : tree[vertex]) {
            if (child == parent) {
                continue;
            }
            self(self, child, vertex);
            dsu.unite(vertex, child);
            ancestor[dsu.find(vertex)] = vertex;
        }
        for (auto [other, index] : by_vertex[vertex]) {
            if (visited[other] != 0) {
                answer[index] = ancestor[dsu.find(other)];
            }
        }
    };
    dfs(dfs, 0, 0);
    for (int i = 0; i < q; ++i) {
        cout << answer[i] + 1 << '\n';
    }
    return 0;
}
