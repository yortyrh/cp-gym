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
    int vertex_count = 2 * n;
    vector<vector<int>> graph(vertex_count);
    auto add_implication = [&](int from, int to) { graph[from].push_back(to); };
    auto literal = [&](int signed_var) {
        int variable = signed_var > 0 ? signed_var - 1 : -signed_var - 1;
        if (signed_var > 0) {
            return variable * 2;
        }
        return variable * 2 + 1;
    };
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        int left = literal(a);
        int right = literal(b);
        add_implication(left ^ 1, right);
        add_implication(right ^ 1, left);
    }
    vector<int> tin(vertex_count, -1);
    vector<int> low(vertex_count, -1);
    vector<char> on_stack(vertex_count, 0);
    vector<int> stack;
    vector<int> component_id(vertex_count, -1);
    int timer = 0;
    int component_count = 0;
    auto dfs = [&](auto&& self, int vertex) -> void {
        tin[vertex] = low[vertex] = timer;
        ++timer;
        stack.push_back(vertex);
        on_stack[vertex] = 1;
        for (int neighbour : graph[vertex]) {
            if (tin[neighbour] == -1) {
                self(self, neighbour);
                low[vertex] = min(low[vertex], low[neighbour]);
            } else if (on_stack[neighbour] != 0) {
                low[vertex] = min(low[vertex], tin[neighbour]);
            }
        }
        if (low[vertex] == tin[vertex]) {
            while (true) {
                int current = stack.back();
                stack.pop_back();
                on_stack[current] = 0;
                component_id[current] = component_count;
                if (current == vertex) {
                    break;
                }
            }
            ++component_count;
        }
    };
    for (int vertex = 0; vertex < vertex_count; ++vertex) {
        if (tin[vertex] == -1) {
            dfs(dfs, vertex);
        }
    }
    vector<int> assignment(n, 0);
    for (int variable = 0; variable < n; ++variable) {
        if (component_id[variable * 2] == component_id[variable * 2 + 1]) {
            cout << "NO\n";
            return 0;
        }
        if (component_id[variable * 2] < component_id[variable * 2 + 1]) {
            assignment[variable] = 1;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << assignment[i];
    }
    cout << '\n';
    return 0;
}
