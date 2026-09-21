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
    vector<int> indegree(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        ++indegree[v];
    }

    priority_queue<int, vector<int>, greater<int>> ready;
    for (int vertex = 0; vertex < n; ++vertex) {
        if (indegree[vertex] == 0) {
            ready.push(vertex);
        }
    }

    vector<int> order;
    while (!ready.empty()) {
        int vertex = ready.top();
        ready.pop();
        order.push_back(vertex);
        for (int neighbour : graph[vertex]) {
            --indegree[neighbour];
            if (indegree[neighbour] == 0) {
                ready.push(neighbour);
            }
        }
    }

    if (static_cast<int>(order.size()) != n) {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << order[i] + 1;
    }
    cout << '\n';
    return 0;
}
