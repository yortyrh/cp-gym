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
    deque<int> pending;
    dist[s] = 0;
    pending.push_back(s);
    while (!pending.empty()) {
        int v = pending.front();
        pending.pop_front();
        for (auto [to, w] : g[v]) {
            if (dist[to] > dist[v] + w) {
                dist[to] = dist[v] + w;
                if (w == 0) {
                    pending.push_front(to);
                } else {
                    pending.push_back(to);
                }
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
