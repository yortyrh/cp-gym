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
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> parent(n, n);
    vector<char> removed(n, 0);
    vector<int> sz(n, 0);
    auto subtree = [&](auto&& self, int vertex, int par) -> int {
        sz[vertex] = 1;
        for (int child : tree[vertex]) {
            if (child == par || removed[child] != 0) {
                continue;
            }
            sz[vertex] += self(self, child, vertex);
        }
        return sz[vertex];
    };
    auto find_centroid = [&](auto&& self, int vertex, int par, int total) -> int {
        for (int child : tree[vertex]) {
            if (child == par || removed[child] != 0) {
                continue;
            }
            if (sz[child] * 2 > total) {
                return self(self, child, vertex, total);
            }
        }
        return vertex;
    };
    auto decompose = [&](auto&& self, int vertex, int par) -> void {
        int total = subtree(subtree, vertex, vertex);
        int centroid = find_centroid(find_centroid, vertex, vertex, total);
        parent[centroid] = par;
        removed[centroid] = 1;
        for (int child : tree[centroid]) {
            if (removed[child] == 0) {
                self(self, child, centroid);
            }
        }
    };
    if (n > 0) {
        decompose(decompose, 0, n);
    }
    for (int vertex = 0; vertex < n; ++vertex) {
        if (vertex > 0) {
            cout << ' ';
        }
        if (parent[vertex] == n) {
            cout << 0;
        } else {
            cout << parent[vertex] + 1;
        }
    }
    cout << '\n';
    return 0;
}
