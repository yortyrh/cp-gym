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
    vector<int> parent(n + 1, 0);
    dist[s] = 0;
    int changed = 0;
    for (int pass = 1; pass <= n; ++pass) {
        changed = 0;
        for (auto [u, v, w] : edges) {
            if (dist[u] != inf && dist[v] > dist[u] + w) {
                dist[v] = max(-inf, dist[u] + w);
                parent[v] = u;
                changed = v;
            }
        }
    }
    if (changed == 0) {
        cout << "NO\n";
        return 0;
    }
    int y = changed;
    for (int i = 0; i < n; ++i) {
        y = parent[y];
    }
    vector<int> cyc;
    int cur = y;
    do {
        cyc.push_back(cur);
        cur = parent[cur];
    } while (cur != y);
    reverse(cyc.begin(), cyc.end());
    int k = cyc.size();
    int pos = 0;
    for (int i = 1; i < k; ++i) {
        if (cyc[i] < cyc[pos]) {
            pos = i;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < k; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << cyc[(pos + i) % k];
    }
    cout << ' ' << cyc[pos] << '\n';
    return 0;
}
