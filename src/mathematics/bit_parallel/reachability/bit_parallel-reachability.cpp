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
    int n, m, q;
    cin >> n >> m >> q;
    vector<bitset<512>> reach(n + 1);
    for (int i = 1; i <= n; ++i) {
        reach[i].set(i);
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        reach[u].set(v);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (reach[i].test(k)) {
                reach[i] |= reach[k];
            }
        }
    }
    while (q--) {
        int u, v;
        cin >> u >> v;
        cout << (reach[u].test(v) ? 1 : 0) << '\n';
    }
    return 0;
}
