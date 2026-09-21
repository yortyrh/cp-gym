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
    int n, colors;
    cin >> n >> colors;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    if (n == 0) {
        cout << 1 << '\n';
        return 0;
    }
    if (colors <= 0) {
        cout << 0 << '\n';
        return 0;
    }
    auto dfs = [&](auto&& self, int vertex, int parent) -> int {
        int ways = 1;
        for (int child : tree[vertex]) {
            if (child == parent) {
                continue;
            }
            ways *= colors - 1;
            ways *= self(self, child, vertex);
        }
        return ways;
    };
    cout << colors * dfs(dfs, 0, 0) << '\n';
    return 0;
}
