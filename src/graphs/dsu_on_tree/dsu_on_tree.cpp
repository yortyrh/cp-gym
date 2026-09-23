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

vector<vector<int>> g;
vector<int> col, sz, heavy, ans, cnt;
int distinct;

void dfs_sz(int u, int p) {
    sz[u] = 1;
    heavy[u] = -1;
    int best = 0;
    for (int v : g[u]) {
        if (v == p) {
            continue;
        }
        dfs_sz(v, u);
        sz[u] += sz[v];
        if (sz[v] > best) {
            best = sz[v];
            heavy[u] = v;
        }
    }
}

void add(int u, int p, int delta) {
    int c = col[u];
    if (delta == 1) {
        if (cnt[c] == 0) {
            ++distinct;
        }
        ++cnt[c];
    } else {
        --cnt[c];
        if (cnt[c] == 0) {
            --distinct;
        }
    }
    for (int v : g[u]) {
        if (v != p) {
            add(v, u, delta);
        }
    }
}

void dfs(int u, int p, bool keep) {
    for (int v : g[u]) {
        if (v == p || v == heavy[u]) {
            continue;
        }
        dfs(v, u, false);
    }
    if (heavy[u] != -1) {
        dfs(heavy[u], u, true);
    }
    for (int v : g[u]) {
        if (v == p || v == heavy[u]) {
            continue;
        }
        add(v, u, 1);
    }
    int c = col[u];
    if (cnt[c] == 0) {
        ++distinct;
    }
    ++cnt[c];
    ans[u] = distinct;
    if (!keep) {
        add(u, p, -1);
    }
}

signed main() {
    int n;
    cin >> n;
    col.assign(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> col[i];
    }
    g.assign(n + 1, {});
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    sz.assign(n + 1, 0);
    heavy.assign(n + 1, -1);
    ans.assign(n + 1, 0);
    int maxc = 0;
    for (int i = 1; i <= n; ++i) {
        maxc = max(maxc, col[i]);
    }
    cnt.assign(maxc + 1, 0);
    distinct = 0;
    dfs_sz(1, 0);
    dfs(1, 0, true);
    for (int i = 1; i <= n; ++i) {
        if (i > 1) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
