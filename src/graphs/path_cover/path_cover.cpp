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

vector<vector<int>> g;
vector<int> mt;
vector<int> used;

bool try_kuhn(int u) {
    for (int v : g[u]) {
        if (used[v]) {
            continue;
        }
        used[v] = 1;
        if (mt[v] == -1 || try_kuhn(mt[v])) {
            mt[v] = u;
            return true;
        }
    }
    return false;
}

signed main() {
    int n, m;
    cin >> n >> m;
    g.assign(n + 1, {});
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    mt.assign(n + 1, -1);
    int matching = 0;
    for (int u = 1; u <= n; ++u) {
        used.assign(n + 1, 0);
        if (try_kuhn(u)) {
            ++matching;
        }
    }
    cout << n - matching << '\n';
    return 0;
}
