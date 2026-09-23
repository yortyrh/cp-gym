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

struct Edge {
    int to;
    int reverse_index;
    int capacity;
};

signed main() {
    int n, m, source, sink;
    cin >> n >> m >> source >> sink;
    --source;
    --sink;
    vector<vector<Edge>> graph(n);
    auto add_edge = [&](int from, int to, int capacity) {
        int to_degree = graph[to].size();
        graph[from].push_back({to, to_degree, capacity});
        int from_degree = graph[from].size();
        graph[to].push_back({from, from_degree - 1, 0});
    };
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        add_edge(u - 1, v - 1, c);
    }
    if (source == sink) {
        cout << 0 << '\n';
        return 0;
    }
    const int inf = 4e18;
    int result = 0;
    while (true) {
        vector<int> parent(n, -1);
        vector<int> parent_edge(n, 0);
        queue<int> pending;
        pending.push(source);
        parent[source] = source;
        while (!pending.empty() && parent[sink] == -1) {
            int vertex = pending.front();
            pending.pop();
            int degree = graph[vertex].size();
            for (int index = 0; index < degree; ++index) {
                const Edge& edge = graph[vertex][index];
                if (edge.capacity > 0 && parent[edge.to] == -1) {
                    parent[edge.to] = vertex;
                    parent_edge[edge.to] = index;
                    pending.push(edge.to);
                }
            }
        }
        if (parent[sink] == -1) {
            break;
        }
        int flow = inf;
        for (int vertex = sink; vertex != source; vertex = parent[vertex]) {
            int previous = parent[vertex];
            flow = min(flow, graph[previous][parent_edge[vertex]].capacity);
        }
        for (int vertex = sink; vertex != source; vertex = parent[vertex]) {
            int previous = parent[vertex];
            Edge& edge = graph[previous][parent_edge[vertex]];
            edge.capacity -= flow;
            graph[edge.to][edge.reverse_index].capacity += flow;
        }
        result += flow;
    }
    cout << result << '\n';
    return 0;
}
