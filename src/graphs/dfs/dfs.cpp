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

    vector<int> seen(n);
    vector<int> order;
    const auto dfs = [&](auto&& self, int vertex) -> void {
        seen[vertex] = 1;
        order.push_back(vertex);
        for (int neighbour : graph[vertex]) {
            if (!seen[neighbour]) {
                self(self, neighbour);
            }
        }
    };
    dfs(dfs, 0);

    for (int i = 0; i < static_cast<int>(order.size()); ++i) {
        if (i) {
            cout << ' ';
        }
        cout << order[i] + 1;
    }
    cout << '\n';
    return 0;
}
