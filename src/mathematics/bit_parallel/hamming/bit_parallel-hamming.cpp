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
    const int W = 60;
    int nw = (m + W - 1) / W;
    if (nw == 0) {
        nw = 1;
    }
    vector<vector<int>> words(n, vector<int>(nw));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            if (s[j] == '1') {
                words[i][j / W] |= (1 << (j % W));
            }
        }
    }
    int ans = 4e18;
    for (int i = 0; i < n; ++i) {
        for (int k = i + 1; k < n; ++k) {
            int d = 0;
            for (int t = 0; t < nw; ++t) {
                d += __builtin_popcountll(words[i][t] ^ words[k][t]);
            }
            ans = min(ans, d);
        }
    }
    cout << ans << '\n';
    return 0;
}
