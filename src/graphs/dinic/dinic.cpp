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
    vector<int> levels(n);
    vector<int> next_edge(n);
    auto build_levels = [&]() -> bool {
        fill(levels.begin(), levels.end(), -1);
        queue<int> pending;
        levels[source] = 0;
        pending.push(source);
        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop();
            for (const Edge& edge : graph[vertex]) {
                if (edge.capacity > 0 && levels[edge.to] < 0) {
                    levels[edge.to] = levels[vertex] + 1;
                    pending.push(edge.to);
                }
            }
        }
        return levels[sink] >= 0;
    };
    auto send_flow = [&](auto&& self, int vertex, int available) -> int {
        if (vertex == sink) {
            return available;
        }
        int degree = graph[vertex].size();
        for (int& index = next_edge[vertex]; index < degree; ++index) {
            Edge& edge = graph[vertex][index];
            if (edge.capacity == 0 || levels[edge.to] != levels[vertex] + 1) {
                continue;
            }
            int flow = self(self, edge.to, min(available, edge.capacity));
            if (flow > 0) {
                edge.capacity -= flow;
                graph[edge.to][edge.reverse_index].capacity += flow;
                return flow;
            }
        }
        return 0;
    };
    int result = 0;
    while (build_levels()) {
        fill(next_edge.begin(), next_edge.end(), 0);
        while (true) {
            int flow = send_flow(send_flow, source, inf);
            if (flow == 0) {
                break;
            }
            result += flow;
        }
    }
    cout << result << '\n';
    return 0;
}
