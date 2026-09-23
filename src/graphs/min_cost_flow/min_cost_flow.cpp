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
    int cost;
};

signed main() {
    int n, m, source, sink, flow_limit;
    cin >> n >> m >> source >> sink >> flow_limit;
    --source;
    --sink;
    vector<vector<Edge>> graph(n);
    auto add_edge = [&](int from, int to, int capacity, int cost) {
        int to_degree = graph[to].size();
        graph[from].push_back({to, to_degree, capacity, cost});
        int from_degree = graph[from].size();
        graph[to].push_back({from, from_degree - 1, 0, -cost});
    };
    for (int i = 0; i < m; ++i) {
        int u, v, cap, cost;
        cin >> u >> v >> cap >> cost;
        add_edge(u - 1, v - 1, cap, cost);
    }
    const int inf = 4e18;
    vector<int> potential(n, 0);
    int result_flow = 0;
    int result_cost = 0;
    while (result_flow < flow_limit) {
        vector<int> distance(n, inf);
        vector<int> parent(n, -1);
        vector<int> parent_edge(n, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pending;
        distance[source] = 0;
        pending.push({0, source});
        while (!pending.empty()) {
            auto [current, vertex] = pending.top();
            pending.pop();
            if (current != distance[vertex]) {
                continue;
            }
            int degree = graph[vertex].size();
            for (int index = 0; index < degree; ++index) {
                const Edge& edge = graph[vertex][index];
                if (edge.capacity <= 0) {
                    continue;
                }
                int relaxed = current + edge.cost + potential[vertex] - potential[edge.to];
                if (relaxed < distance[edge.to]) {
                    distance[edge.to] = relaxed;
                    parent[edge.to] = vertex;
                    parent_edge[edge.to] = index;
                    pending.push({relaxed, edge.to});
                }
            }
        }
        if (distance[sink] == inf) {
            break;
        }
        for (int vertex = 0; vertex < n; ++vertex) {
            if (distance[vertex] < inf) {
                potential[vertex] += distance[vertex];
            }
        }
        int add = flow_limit - result_flow;
        for (int vertex = sink; vertex != source; vertex = parent[vertex]) {
            int previous = parent[vertex];
            add = min(add, graph[previous][parent_edge[vertex]].capacity);
        }
        for (int vertex = sink; vertex != source; vertex = parent[vertex]) {
            int previous = parent[vertex];
            Edge& edge = graph[previous][parent_edge[vertex]];
            edge.capacity -= add;
            graph[edge.to][edge.reverse_index].capacity += add;
            result_cost += add * edge.cost;
        }
        result_flow += add;
    }
    cout << result_flow << ' ' << result_cost << '\n';
    return 0;
}
