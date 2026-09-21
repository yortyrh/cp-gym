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
    vector<int> is_cut(n);
    int timer = 0;

    const auto dfs = [&](auto&& self, int vertex, int parent) -> void {
        tin[vertex] = low[vertex] = timer++;
        int children = 0;
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
            if (parent != vertex && low[neighbour] >= tin[vertex]) {
                is_cut[vertex] = 1;
            }
            ++children;
        }
        if (parent == vertex && children > 1) {
            is_cut[vertex] = 1;
        }
    };

    for (int vertex = 0; vertex < n; ++vertex) {
        if (tin[vertex] == -1) {
            dfs(dfs, vertex, vertex);
        }
    }

    vector<int> cut_points;
    for (int vertex = 0; vertex < n; ++vertex) {
        if (is_cut[vertex]) {
            cut_points.push_back(vertex + 1);
        }
    }

    cout << cut_points.size() << '\n';
    if (!cut_points.empty()) {
        for (int i = 0; i < static_cast<int>(cut_points.size()); ++i) {
            if (i) {
                cout << ' ';
            }
            cout << cut_points[i];
        }
        cout << '\n';
    }
    return 0;
}
