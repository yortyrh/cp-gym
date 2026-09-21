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

struct DSU {
    vector<int> parent;

    explicit DSU(int n) : parent(n) { iota(parent.begin(), parent.end(), 0); }

    int find(int v) {
        int root = v;
        while (parent[root] != root) {
            root = parent[root];
        }
        while (parent[v] != root) {
            int nxt = parent[v];
            parent[v] = root;
            v = nxt;
        }
        return root;
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> left(q), right(q), color_op(q);
    for (int i = 0; i < q; ++i) {
        cin >> left[i] >> right[i] >> color_op[i];
    }
    DSU dsu(n + 2);
    vector<int> color(n + 1);
    for (int i = q - 1; i >= 0; --i) {
        int pos = dsu.find(left[i]);
        while (pos <= right[i]) {
            color[pos] = color_op[i];
            dsu.parent[pos] = dsu.find(pos + 1);
            pos = dsu.parent[pos];
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << color[i];
    }
    cout << '\n';
    return 0;
}
