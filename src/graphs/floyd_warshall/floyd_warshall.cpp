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
    const int inf = 4e18;
    vector<vector<int>> distance(n, vector<int>(n, inf));
    for (int i = 0; i < n; ++i) {
        distance[i][i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;
        distance[u][v] = min(distance[u][v], w);
    }
    for (int through = 0; through < n; ++through) {
        for (int from = 0; from < n; ++from) {
            for (int to = 0; to < n; ++to) {
                if (distance[from][through] != inf && distance[through][to] != inf) {
                    distance[from][to] =
                        min(distance[from][to], distance[from][through] + distance[through][to]);
                }
            }
        }
    }
    for (int from = 0; from < n; ++from) {
        for (int to = 0; to < n; ++to) {
            if (to > 0) {
                cout << ' ';
            }
            if (distance[from][to] == inf) {
                cout << -1;
            } else {
                cout << distance[from][to];
            }
        }
        cout << '\n';
    }
    return 0;
}
