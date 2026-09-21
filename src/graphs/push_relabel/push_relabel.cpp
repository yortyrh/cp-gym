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
    vector<int> height(n, 0);
    vector<int> excess(n, 0);
    height[source] = n;
    queue<int> pending;
    vector<char> in_queue(n, 0);
    int source_degree = graph[source].size();
    for (int index = 0; index < source_degree; ++index) {
        Edge& edge = graph[source][index];
        if (edge.capacity == 0) {
            continue;
        }
        int flow = edge.capacity;
        edge.capacity = 0;
        graph[edge.to][edge.reverse_index].capacity += flow;
        excess[edge.to] += flow;
        if (edge.to != source && edge.to != sink && in_queue[edge.to] == 0) {
            pending.push(edge.to);
            in_queue[edge.to] = 1;
        }
    }
    const int inf_height = 4e18;
    while (!pending.empty()) {
        int vertex = pending.front();
        pending.pop();
        in_queue[vertex] = 0;
        int degree = graph[vertex].size();
        for (int index = 0; index < degree && excess[vertex] > 0; ++index) {
            Edge& edge = graph[vertex][index];
            int flow = min(excess[vertex], edge.capacity);
            if (flow == 0 || height[vertex] != height[edge.to] + 1) {
                continue;
            }
            edge.capacity -= flow;
            graph[edge.to][edge.reverse_index].capacity += flow;
            excess[vertex] -= flow;
            excess[edge.to] += flow;
            if (edge.to != source && edge.to != sink && in_queue[edge.to] == 0 &&
                excess[edge.to] > 0) {
                pending.push(edge.to);
                in_queue[edge.to] = 1;
            }
        }
        if (excess[vertex] > 0) {
            int min_height = inf_height;
            for (const Edge& edge : graph[vertex]) {
                if (edge.capacity > 0) {
                    min_height = min(min_height, height[edge.to]);
                }
            }
            if (min_height != inf_height) {
                height[vertex] = min_height + 1;
                pending.push(vertex);
                in_queue[vertex] = 1;
            }
        }
    }
    cout << excess[sink] << '\n';
    return 0;
}
