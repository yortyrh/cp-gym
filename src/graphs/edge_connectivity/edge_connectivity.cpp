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

struct Edge {
    int to;
    int reverse_index;
    int capacity;
};

int max_flow(vector<vector<Edge>> graph, int source, int sink) {
    if (source == sink) {
        return 0;
    }
    int n = graph.size();
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
    return result;
}

signed main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (n <= 1) {
        cout << 0 << '\n';
        return 0;
    }
    vector<vector<Edge>> network(n);
    auto add_edge = [&](int from, int to, int capacity) {
        int to_degree = network[to].size();
        network[from].push_back({to, to_degree, capacity});
        int from_degree = network[from].size();
        network[to].push_back({from, from_degree - 1, 0});
    };
    for (int from = 0; from < n; ++from) {
        for (int to : adj[from]) {
            if (from < to) {
                add_edge(from, to, 1);
                add_edge(to, from, 1);
            }
        }
    }
    int best = 4e18;
    for (int sink = 1; sink < n; ++sink) {
        best = min(best, max_flow(network, 0, sink));
    }
    cout << best << '\n';
    return 0;
}
