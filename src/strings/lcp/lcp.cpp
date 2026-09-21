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

vector<int> build_suffix_array(const string& s) {
    int n = s.size();
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
    return suffixes;
}

signed main() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> suffixes = build_suffix_array(s);
    vector<int> rank(n);
    for (int i = 0; i < n; ++i) {
        rank[suffixes[i]] = i;
    }
    vector<int> lcp(n);
    int common = 0;
    for (int suffix = 0; suffix < n; ++suffix) {
        if (rank[suffix] == 0) {
            continue;
        }
        int previous = suffixes[rank[suffix] - 1];
        while (suffix + common < n && previous + common < n &&
               s[suffix + common] == s[previous + common]) {
            ++common;
        }
        lcp[rank[suffix]] = common;
        if (common > 0) {
            --common;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << lcp[i];
    }
    cout << '\n';
    return 0;
}
