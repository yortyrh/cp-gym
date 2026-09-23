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
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> pref(n + 1);
    for (int i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + a[i];
    }
    auto cost = [&](int l, int r) {
        int s = pref[r] - pref[l - 1];
        return s * s;
    };
    const int inf = 4e18;
    vector<int> prev(n + 1, inf);
    vector<int> cur(n + 1, inf);
    prev[0] = 0;
    function<void(int, int, int, int)> solve = [&](int l, int r, int optl, int optr) {
        if (l > r) {
            return;
        }
        int mid = (l + r) / 2;
        int best = inf;
        int opt = optl;
        int hi = min(optr, mid - 1);
        for (int j = optl; j <= hi; ++j) {
            int val = prev[j] + cost(j + 1, mid);
            if (val < best) {
                best = val;
                opt = j;
            }
        }
        cur[mid] = best;
        solve(l, mid - 1, optl, opt);
        solve(mid + 1, r, opt, optr);
    };
    for (int g = 1; g <= k; ++g) {
        for (int i = 0; i <= n; ++i) {
            cur[i] = inf;
        }
        solve(g, n, g - 1, n - 1);
        prev.swap(cur);
    }
    cout << prev[n] << '\n';
    return 0;
}
