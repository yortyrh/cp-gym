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
        graph[v].push_back(u);
    }

    vector<int> tin(n, -1), low(n, -1);
    vector<pair<int, int>> bridges;
    int timer = 0;

    const auto dfs = [&](auto&& self, int vertex, int parent) -> void {
        tin[vertex] = low[vertex] = timer++;
        for (int neighbour : graph[vertex]) {
            if (neighbour == parent) {
                continue;
            }
            if (tin[neighbour] != -1) {
                low[vertex] = min(low[vertex], tin[neighbour]);
                continue;
            }
            self(self, neighbour, vertex);
            low[vertex] = min(low[vertex], low[neighbour]);
            if (low[neighbour] > tin[vertex]) {
                bridges.emplace_back(min(vertex, neighbour), max(vertex, neighbour));
            }
        }
    };

    for (int vertex = 0; vertex < n; ++vertex) {
        if (tin[vertex] == -1) {
            dfs(dfs, vertex, vertex);
        }
    }
    sort(bridges.begin(), bridges.end());

    cout << bridges.size() << '\n';
    for (auto [u, v] : bridges) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
