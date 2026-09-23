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
    }

    vector<int> tin(n, -1), low(n, -1), on_stack(n);
    vector<int> stack;
    vector<vector<int>> components;
    int timer = 0;
    const auto dfs = [&](auto&& self, int vertex) -> void {
        tin[vertex] = low[vertex] = timer++;
        stack.push_back(vertex);
        on_stack[vertex] = 1;
        for (int neighbour : graph[vertex]) {
            if (tin[neighbour] == -1) {
                self(self, neighbour);
                low[vertex] = min(low[vertex], low[neighbour]);
            } else if (on_stack[neighbour]) {
                low[vertex] = min(low[vertex], tin[neighbour]);
            }
        }
        if (low[vertex] == tin[vertex]) {
            vector<int> component;
            while (true) {
                int current = stack.back();
                stack.pop_back();
                on_stack[current] = 0;
                component.push_back(current);
                if (current == vertex) {
                    break;
                }
            }
            components.push_back(move(component));
        }
    };
    for (int vertex = 0; vertex < n; ++vertex) {
        if (tin[vertex] == -1) {
            dfs(dfs, vertex);
        }
    }

    int k = static_cast<int>(components.size());
    vector<int> smallest(k, n);
    for (int i = 0; i < k; ++i) {
        for (int vertex : components[i]) {
            smallest[i] = min(smallest[i], vertex);
        }
    }
    vector<int> order(k);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) { return smallest[a] < smallest[b]; });
    vector<int> remap(k);
    for (int i = 0; i < k; ++i) {
        remap[order[i]] = i + 1;
    }
    vector<int> component_id(n);
    for (int i = 0; i < k; ++i) {
        for (int vertex : components[i]) {
            component_id[vertex] = remap[i];
        }
    }

    cout << k << '\n';
    for (int vertex = 0; vertex < n; ++vertex) {
        if (vertex) {
            cout << ' ';
        }
        cout << component_id[vertex];
    }
    cout << '\n';
    return 0;
}
