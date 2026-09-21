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
    string text, pattern;
    cin >> text >> pattern;
    int n = text.size();
    int m = pattern.size();
    vector<int> pi(m);
    for (int i = 1; i < m; ++i) {
        int border = pi[i - 1];
        while (border > 0 && pattern[i] != pattern[border]) {
            border = pi[border - 1];
        }
        if (pattern[i] == pattern[border]) {
            ++border;
        }
        pi[i] = border;
    }
    vector<int> matches;
    int matched = 0;
    for (int i = 0; i < n; ++i) {
        while (matched > 0 && text[i] != pattern[matched]) {
            matched = pi[matched - 1];
        }
        if (text[i] == pattern[matched]) {
            ++matched;
        }
        if (matched == m) {
            matches.push_back(i + 1 - m);
            matched = pi[matched - 1];
        }
    }
    cout << matches.size() << '\n';
    bool first = true;
    for (int pos : matches) {
        if (!first) {
            cout << ' ';
        }
        first = false;
        cout << pos;
    }
    if (!matches.empty()) {
        cout << '\n';
    }
    return 0;
}
