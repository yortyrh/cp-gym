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
    int timer = 0;
    bool has_bridge = false;
    const auto find_bridges = [&](auto&& self, int vertex, int parent) -> void {
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
                has_bridge = true;
            }
        }
    };
    for (int vertex = 0; vertex < n; ++vertex) {
        if (tin[vertex] == -1) {
            find_bridges(find_bridges, vertex, vertex);
        }
    }
    if (has_bridge) {
        cout << "NO\n";
        return 0;
    }

    fill(tin.begin(), tin.end(), -1);
    timer = 0;
    vector<pair<int, int>> directed;
    const auto orient = [&](auto&& self, int vertex, int parent) -> void {
        tin[vertex] = timer++;
        for (int neighbour : graph[vertex]) {
            if (neighbour == parent) {
                continue;
            }
            if (tin[neighbour] == -1) {
                directed.emplace_back(vertex, neighbour);
                self(self, neighbour, vertex);
            } else if (tin[neighbour] < tin[vertex]) {
                directed.emplace_back(vertex, neighbour);
            }
        }
    };
    for (int vertex = 0; vertex < n; ++vertex) {
        if (tin[vertex] == -1) {
            orient(orient, vertex, vertex);
        }
    }

    cout << "YES\n";
    for (auto [u, v] : directed) {
        cout << u + 1 << ' ' << v + 1 << '\n';
    }
    return 0;
}
