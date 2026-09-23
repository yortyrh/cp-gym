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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
    }

    vector<int> state(n);
    const auto dfs = [&](auto&& self, int vertex) -> bool {
        state[vertex] = 1;
        for (int neighbour : graph[vertex]) {
            if (state[neighbour] == 1) {
                return true;
            }
            if (state[neighbour] == 0 && self(self, neighbour)) {
                return true;
            }
        }
        state[vertex] = 2;
        return false;
    };

    for (int vertex = 0; vertex < n; ++vertex) {
        if (state[vertex] == 0 && dfs(dfs, vertex)) {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
