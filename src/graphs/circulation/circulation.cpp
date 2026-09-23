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
    int n, m;
    cin >> n >> m;
    vector<int> demand(n);
    int total = 0;
    for (int i = 0; i < n; ++i) {
        cin >> demand[i];
        total += demand[i];
    }
    vector<array<int, 3>> capacities(m);
    for (int i = 0; i < m; ++i) {
        cin >> capacities[i][0] >> capacities[i][1] >> capacities[i][2];
        --capacities[i][0];
        --capacities[i][1];
    }
    if (total != 0) {
        cout << "NO\n";
        return 0;
    }
    int source = n;
    int sink = n + 1;
    int vertex_count = n + 2;
    vector<vector<Edge>> graph(vertex_count);
    auto add_edge = [&](int from, int to, int capacity) {
        int to_degree = graph[to].size();
        graph[from].push_back({to, to_degree, capacity});
        int from_degree = graph[from].size();
        graph[to].push_back({from, from_degree - 1, 0});
    };
    int required = 0;
    for (int vertex = 0; vertex < n; ++vertex) {
        if (demand[vertex] > 0) {
            add_edge(vertex, sink, demand[vertex]);
            required += demand[vertex];
        } else if (demand[vertex] < 0) {
            add_edge(source, vertex, -demand[vertex]);
        }
    }
    for (auto [from, to, cap] : capacities) {
        add_edge(from, to, cap);
    }
    const int inf = 4e18;
    int result = 0;
    while (true) {
        vector<int> parent(vertex_count, -1);
        vector<int> parent_edge(vertex_count, 0);
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
    if (result == required) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}
