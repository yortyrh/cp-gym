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
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> eu(m), ev(m);
    for (int i = 0; i < m; ++i) {
        cin >> eu[i] >> ev[i];
    }
    vector<int> qu(q), qv(q);
    for (int i = 0; i < q; ++i) {
        cin >> qu[i] >> qv[i];
    }
    vector<int> L(q, 1);
    vector<int> R(q, m + 1);
    while (true) {
        bool any = false;
        vector<vector<int>> bucket(m + 2);
        for (int i = 0; i < q; ++i) {
            if (L[i] < R[i]) {
                any = true;
                int mid = (L[i] + R[i]) / 2;
                bucket[mid].push_back(i);
            }
        }
        if (!any) {
            break;
        }
        vector<int> p(n + 1);
        vector<int> sz(n + 1, 1);
        iota(p.begin(), p.end(), 0);
        function<int(int)> find = [&](int x) {
            if (p[x] == x) {
                return x;
            }
            p[x] = find(p[x]);
            return p[x];
        };
        auto unite = [&](int a, int b) {
            a = find(a);
            b = find(b);
            if (a == b) {
                return;
            }
            if (sz[a] < sz[b]) {
                swap(a, b);
            }
            p[b] = a;
            sz[a] += sz[b];
        };
        for (int t = 1; t <= m; ++t) {
            unite(eu[t - 1], ev[t - 1]);
            for (int i : bucket[t]) {
                if (find(qu[i]) == find(qv[i])) {
                    R[i] = t;
                } else {
                    L[i] = t + 1;
                }
            }
        }
    }
    for (int i = 0; i < q; ++i) {
        if (L[i] == m + 1) {
            cout << -1 << '\n';
        } else {
            cout << L[i] << '\n';
        }
    }
    return 0;
}
