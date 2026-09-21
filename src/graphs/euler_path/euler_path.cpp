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
    vector<int> indegree(n, 0);
    vector<int> outdegree(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        graph[u].push_back(v);
        ++outdegree[u];
        ++indegree[v];
    }
    if (m == 0) {
        cout << "YES\n1\n";
        return 0;
    }
    int start = n;
    int start_candidates = 0;
    int end_candidates = 0;
    for (int vertex = 0; vertex < n; ++vertex) {
        int out = outdegree[vertex];
        int in = indegree[vertex];
        if (out == in + 1) {
            start = vertex;
            ++start_candidates;
        } else if (in == out + 1) {
            ++end_candidates;
        } else if (in != out) {
            cout << "NO\n";
            return 0;
        }
    }
    if (!((start_candidates == 0 && end_candidates == 0) ||
          (start_candidates == 1 && end_candidates == 1))) {
        cout << "NO\n";
        return 0;
    }
    if (start == n) {
        for (int vertex = 0; vertex < n; ++vertex) {
            if (outdegree[vertex] > 0) {
                start = vertex;
                break;
            }
        }
    }
    vector<int> stack{start};
    vector<int> path;
    vector<int> next_edge(n, 0);
    while (!stack.empty()) {
        int vertex = stack.back();
        if (next_edge[vertex] < outdegree[vertex]) {
            int nxt = graph[vertex][next_edge[vertex]];
            ++next_edge[vertex];
            stack.push_back(nxt);
        } else {
            path.push_back(vertex);
            stack.pop_back();
        }
    }
    reverse(path.begin(), path.end());
    int path_len = path.size();
    if (path_len != m + 1) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = 0; i < path_len; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << path[i] + 1;
    }
    cout << '\n';
    return 0;
}
