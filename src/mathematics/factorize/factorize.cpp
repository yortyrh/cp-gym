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
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        vector<pair<int, int>> factors;
        int value = n;
        for (int p = 2; p <= value / p; ++p) {
            if (value % p == 0) {
                int exp = 0;
                while (value % p == 0) {
                    value /= p;
                    ++exp;
                }
                factors.push_back({p, exp});
            }
        }
        if (value > 1) {
            factors.push_back({value, 1});
        }
        cout << factors.size() << '\n';
        for (auto [p, e] : factors) {
            cout << p << ' ' << e << '\n';
        }
    }
    return 0;
}
