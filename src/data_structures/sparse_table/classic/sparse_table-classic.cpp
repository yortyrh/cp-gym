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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> lg(n + 1);
    lg[1] = 0;
    for (int i = 2; i <= n; ++i) {
        lg[i] = lg[i / 2] + 1;
    }
    int k_max = lg[n] + 1;
    vector<vector<int>> st(k_max, vector<int>(n + 1));
    for (int i = 1; i <= n; ++i) {
        st[0][i] = a[i];
    }
    for (int k = 1; k < k_max; ++k) {
        int len = 1;
        for (int i = 0; i < k; ++i) {
            len += len;
        }
        int half = len / 2;
        for (int i = 1; i + len - 1 <= n; ++i) {
            st[k][i] = min(st[k - 1][i], st[k - 1][i + half]);
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        int k = lg[r - l + 1];
        int len = 1;
        for (int i = 0; i < k; ++i) {
            len += len;
        }
        cout << min(st[k][l], st[k][r - len + 1]) << '\n';
    }
    return 0;
}
