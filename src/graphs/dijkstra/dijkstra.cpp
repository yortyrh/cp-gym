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
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    const int inf = 4e18;
    vector<int> dist(n + 1, inf);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pending;
    pending.push({0, s});
    while (!pending.empty()) {
        auto [current, v] = pending.top();
        pending.pop();
        if (current != dist[v]) {
            continue;
        }
        for (auto [to, w] : g[v]) {
            if (dist[to] > current + w) {
                dist[to] = current + w;
                pending.push({dist[to], to});
            }
        }
    }
    for (int v = 1; v <= n; ++v) {
        if (v > 1) {
            cout << ' ';
        }
        if (dist[v] == inf) {
            cout << "INF";
        } else {
            cout << dist[v];
        }
    }
    cout << '\n';
    return 0;
}
