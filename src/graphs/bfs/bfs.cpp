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
    }

    const int inf = 4e18;
    vector<int> distance(n, inf);
    queue<int> pending;
    distance[0] = 0;
    pending.push(0);
    while (!pending.empty()) {
        int vertex = pending.front();
        pending.pop();
        for (int neighbour : graph[vertex]) {
            if (distance[neighbour] == inf) {
                distance[neighbour] = distance[vertex] + 1;
                pending.push(neighbour);
            }
        }
    }

    for (int vertex = 0; vertex < n; ++vertex) {
        if (vertex) {
            cout << ' ';
        }
        if (distance[vertex] == inf) {
            cout << -1;
        } else {
            cout << distance[vertex];
        }
    }
    cout << '\n';
    return 0;
}
