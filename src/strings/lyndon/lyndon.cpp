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
    vector<string> factors;
    int begin = 0;
    while (begin < n) {
        int i = begin;
        int j = begin + 1;
        while (j < n && s[i] <= s[j]) {
            if (s[i] < s[j]) {
                i = begin;
            } else {
                ++i;
            }
            ++j;
        }
        int period = j - i;
        while (begin <= i) {
            factors.push_back(s.substr(begin, period));
            begin += period;
        }
    }
    bool first = true;
    for (const string& factor : factors) {
        if (!first) {
            cout << ' ';
        }
        first = false;
        cout << factor;
    }
    cout << '\n';
    return 0;
}
