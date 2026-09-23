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

    vector<int> color(n, -1);
    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) {
            continue;
        }
        queue<int> pending;
        color[start] = 0;
        pending.push(start);
        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop();
            for (int neighbour : graph[vertex]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = color[vertex] ^ 1;
                    pending.push(neighbour);
                } else if (color[neighbour] == color[vertex]) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    for (int vertex = 0; vertex < n; ++vertex) {
        if (vertex) {
            cout << ' ';
        }
        cout << color[vertex] + 1;
    }
    cout << '\n';
    return 0;
}
