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
    int n, q;
    cin >> n >> q;
    const int LOG = 60;
    vector<vector<int>> up(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        cin >> up[0][i];
    }
    for (int b = 1; b < LOG; ++b) {
        for (int i = 1; i <= n; ++i) {
            up[b][i] = up[b - 1][up[b - 1][i]];
        }
    }
    while (q--) {
        int x, k;
        cin >> x >> k;
        for (int b = 0; b < LOG; ++b) {
            if ((k >> b) & 1) {
                x = up[b][x];
            }
        }
        cout << x << '\n';
    }
    return 0;
}
