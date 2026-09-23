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
    vector<array<int, 3>> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }
    const int inf = 4e18;
    vector<int> dist(n + 1, inf);
    dist[s] = 0;
    for (int pass = 1; pass < n; ++pass) {
        bool changed = false;
        for (auto [u, v, w] : edges) {
            if (dist[u] != inf && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                changed = true;
            }
        }
        if (!changed) {
            break;
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
