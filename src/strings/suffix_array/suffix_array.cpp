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
    vector<int> suffixes(n);
    for (int i = 0; i < n; ++i) {
        suffixes[i] = i;
    }
    vector<int> rank(n);
    vector<int> next_rank(n);
    for (int i = 0; i < n; ++i) {
        rank[i] = static_cast<unsigned char>(s[i]);
    }
    for (int length = 1; length < n; length *= 2) {
        auto key = [&](int index) {
            int second = index + length < n ? rank[index + length] : -1;
            return pair<int, int>{rank[index], second};
        };
        sort(suffixes.begin(), suffixes.end(),
             [&](int lhs, int rhs) { return key(lhs) < key(rhs); });
        next_rank[suffixes[0]] = 0;
        for (int i = 1; i < n; ++i) {
            next_rank[suffixes[i]] =
                next_rank[suffixes[i - 1]] + (key(suffixes[i - 1]) != key(suffixes[i]) ? 1 : 0);
        }
        rank.swap(next_rank);
        if (rank[suffixes[n - 1]] == n - 1) {
            break;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << suffixes[i];
    }
    cout << '\n';
    return 0;
}
