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
    vector<vector<int>> up(n, vector<int>(1, 0));
    vector<int> depth(n, 0);
    auto dfs = [&](auto&& self, int vertex, int parent) -> void {
        up[vertex][0] = parent;
        for (int child : tree[vertex]) {
            if (child == parent) {
                continue;
            }
            depth[child] = depth[vertex] + 1;
            self(self, child, vertex);
        }
    };
    dfs(dfs, 0, 0);
    int levels = 1;
    int span = 1;
    while (span <= n) {
        span *= 2;
        ++levels;
    }
    for (int vertex = 0; vertex < n; ++vertex) {
        up[vertex].resize(levels, 0);
    }
    for (int level = 1; level < levels; ++level) {
        for (int vertex = 0; vertex < n; ++vertex) {
            up[vertex][level] = up[up[vertex][level - 1]][level - 1];
        }
    }
    auto query = [&](int lhs, int rhs) {
        if (depth[lhs] < depth[rhs]) {
            swap(lhs, rhs);
        }
        int diff = depth[lhs] - depth[rhs];
        for (int level = 0; level < levels; ++level) {
            if ((diff & (1 << level)) != 0) {
                lhs = up[lhs][level];
            }
        }
        if (lhs == rhs) {
            return lhs;
        }
        for (int level = levels - 1; level >= 0; --level) {
            if (up[lhs][level] != up[rhs][level]) {
                lhs = up[lhs][level];
                rhs = up[rhs][level];
            }
        }
        return up[lhs][0];
    };
    while (q--) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        cout << query(u, v) + 1 << '\n';
    }
    return 0;
}
