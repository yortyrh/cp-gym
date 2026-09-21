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
    int n, s;
    cin >> n >> s;
    vector<int> sub(s);
    for (int i = 0; i < s; ++i) {
        cin >> sub[i];
    }
    vector<int> pile(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> pile[i];
        mx = max(mx, pile[i]);
    }
    vector<int> g(mx + 1);
    for (int x = 1; x <= mx; ++x) {
        vector<int> seen(s + 2);
        for (int d : sub) {
            if (d <= x) {
                int v = g[x - d];
                if (v < s + 2) {
                    seen[v] = 1;
                }
            }
        }
        int mex = 0;
        while (mex < s + 2 && seen[mex]) {
            ++mex;
        }
        g[x] = mex;
    }
    int xr = 0;
    for (int p : pile) {
        xr ^= g[p];
    }
    if (xr) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}
