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

int n;
vector<vector<int>> cap;
vector<vector<int>> adj;

bool dfs(int u, int t, vector<int>& vis) {
    if (u == t) {
        return true;
    }
    vis[u] = 1;
    for (int v : adj[u]) {
        if (!vis[v] && cap[u][v] > 0) {
            if (dfs(v, t, vis)) {
                --cap[u][v];
                ++cap[v][u];
                return true;
            }
        }
    }
    return false;
}

signed main() {
    int m;
    cin >> n >> m;
    cap.assign(n + 1, vector<int>(n + 1));
    adj.assign(n + 1, {});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (cap[u][v] == 0 && cap[v][u] == 0) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ++cap[u][v];
    }
    int ans = 0;
    while (true) {
        vector<int> vis(n + 1);
        if (!dfs(1, n, vis)) {
            break;
        }
        ++ans;
    }
    cout << ans << '\n';
    return 0;
}
