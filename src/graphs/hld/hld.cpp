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

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> raw(n);
    for (int i = 0; i < n; ++i) {
        cin >> raw[i];
    }
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> parent(n), depth(n, 0), heavy(n, n), head(n), position(n), subtree(n, 1);
    auto dfs_size = [&](auto&& self, int vertex, int par) -> void {
        parent[vertex] = par;
        int best = n;
        int best_size = 0;
        for (int child : tree[vertex]) {
            if (child == par) {
                continue;
            }
            depth[child] = depth[vertex] + 1;
            self(self, child, vertex);
            subtree[vertex] += subtree[child];
            if (subtree[child] > best_size) {
                best_size = subtree[child];
                best = child;
            }
        }
        heavy[vertex] = best;
    };
    dfs_size(dfs_size, 0, 0);
    int timer = 0;
    auto dfs_hld = [&](auto&& self, int vertex, int chain) -> void {
        head[vertex] = chain;
        position[vertex] = timer;
        ++timer;
        if (heavy[vertex] != n) {
            self(self, heavy[vertex], chain);
        }
        for (int child : tree[vertex]) {
            if (child == parent[vertex] || child == heavy[vertex]) {
                continue;
            }
            self(self, child, child);
        }
    };
    dfs_hld(dfs_hld, 0, 0);
    vector<int> values(n, 0);
    for (int vertex = 0; vertex < n; ++vertex) {
        values[position[vertex]] = raw[vertex];
    }
    auto path_sum = [&](int lhs, int rhs) {
        int total = 0;
        while (head[lhs] != head[rhs]) {
            if (depth[head[lhs]] < depth[head[rhs]]) {
                swap(lhs, rhs);
            }
            int chain = head[lhs];
            for (int index = position[chain]; index <= position[lhs]; ++index) {
                total += values[index];
            }
            lhs = parent[chain];
        }
        if (depth[lhs] > depth[rhs]) {
            swap(lhs, rhs);
        }
        for (int index = position[lhs]; index <= position[rhs]; ++index) {
            total += values[index];
        }
        return total;
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int vertex, value;
            cin >> vertex >> value;
            --vertex;
            values[position[vertex]] = value;
        } else {
            int u, v;
            cin >> u >> v;
            --u;
            --v;
            cout << path_sum(u, v) << '\n';
        }
    }
    return 0;
}
