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
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << pi[i];
    }
    cout << '\n';
    return 0;
}
