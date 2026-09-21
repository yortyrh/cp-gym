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
    vector<vector<pair<int, int>>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    vector<char> used(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pending;
    int total = 0;
    int taken = 0;
    auto add_vertex = [&](int v) {
        used[v] = 1;
        for (auto [to, w] : g[v]) {
            if (used[to] == 0) {
                pending.push({w, to});
            }
        }
    };
    add_vertex(1);
    while (!pending.empty() && taken < n - 1) {
        auto [w, v] = pending.top();
        pending.pop();
        if (used[v] != 0) {
            continue;
        }
        total += w;
        ++taken;
        add_vertex(v);
    }
    if (n > 0 && taken != n - 1) {
        cout << -1 << '\n';
    } else {
        cout << total << '\n';
    }
    return 0;
}
