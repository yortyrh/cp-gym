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
    int n;
    string s;
    cin >> n >> s;
    vector<int> z(n);
    int left = 0;
    int right = 0;
    for (int i = 1; i < n; ++i) {
        if (i < right) {
            z[i] = min(right - i, z[i - left]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] > right) {
            left = i;
            right = i + z[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << z[i];
    }
    cout << '\n';
    return 0;
}
