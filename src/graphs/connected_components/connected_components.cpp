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

    vector<int> seen(n);
    vector<int> component(n);
    int component_count = 0;
    const auto dfs = [&](auto&& self, int vertex, int id) -> void {
        seen[vertex] = 1;
        component[vertex] = id;
        for (int neighbour : graph[vertex]) {
            if (!seen[neighbour]) {
                self(self, neighbour, id);
            }
        }
    };
    for (int vertex = 0; vertex < n; ++vertex) {
        if (!seen[vertex]) {
            ++component_count;
            dfs(dfs, vertex, component_count);
        }
    }

    cout << component_count << '\n';
    for (int vertex = 0; vertex < n; ++vertex) {
        if (vertex) {
            cout << ' ';
        }
        cout << component[vertex];
    }
    cout << '\n';
    return 0;
}
