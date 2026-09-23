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
    int n;
    string s;
    cin >> n >> s;
    vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int border = pi[i - 1];
        while (border > 0 && s[i] != s[border]) {
            border = pi[border - 1];
        }
        if (s[i] == s[border]) {
            ++border;
        }
        pi[i] = border;
    }
    vector<int> occ(n + 1);
    for (int i = 0; i < n; ++i) {
        ++occ[pi[i]];
    }
    for (int i = n - 1; i > 0; --i) {
        occ[pi[i - 1]] += occ[i];
    }
    for (int i = 0; i <= n; ++i) {
        ++occ[i];
    }
    for (int k = 1; k <= n; ++k) {
        if (k > 1) {
            cout << ' ';
        }
        cout << occ[k];
    }
    cout << '\n';
    return 0;
}
