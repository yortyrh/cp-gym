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
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    vector<int> sz(n, 1);
    vector<int> down(n, 0);
    vector<int> answer(n, 0);
    auto dfs_down = [&](auto&& self, int vertex, int parent) -> void {
        for (int child : tree[vertex]) {
            if (child == parent) {
                continue;
            }
            self(self, child, vertex);
            sz[vertex] += sz[child];
            down[vertex] += down[child] + sz[child];
        }
    };
    auto dfs_up = [&](auto&& self, int vertex, int parent) -> void {
        for (int child : tree[vertex]) {
            if (child == parent) {
                continue;
            }
            answer[child] = answer[vertex] - sz[child] + (n - sz[child]);
            self(self, child, vertex);
        }
    };
    if (n > 0) {
        dfs_down(dfs_down, 0, 0);
        answer[0] = down[0];
        dfs_up(dfs_up, 0, 0);
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << answer[i];
    }
    cout << '\n';
    return 0;
}
