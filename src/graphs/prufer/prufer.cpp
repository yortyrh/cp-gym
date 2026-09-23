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
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> degree(n + 1);
    vector<char> removed(n + 1, 0);
    for (int v = 1; v <= n; ++v) {
        degree[v] = g[v].size();
    }
    vector<int> code;
    code.reserve(n >= 2 ? n - 2 : 0);
    for (int step = 0; step < n - 2; ++step) {
        int leaf = n + 1;
        for (int v = 1; v <= n; ++v) {
            if (removed[v] == 0 && degree[v] == 1) {
                leaf = v;
                break;
            }
        }
        int neighbour = n + 1;
        for (int cand : g[leaf]) {
            if (removed[cand] == 0) {
                neighbour = cand;
                break;
            }
        }
        code.push_back(neighbour);
        removed[leaf] = 1;
        --degree[leaf];
        --degree[neighbour];
    }
    for (int i = 0; i < n - 2; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << code[i];
    }
    cout << '\n';
    return 0;
}
