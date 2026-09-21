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

struct Trie {
    vector<array<int, 26>> nxt;
    vector<int> pref;

    Trie() { add_node(); }

    int add_node() {
        nxt.push_back({});
        nxt.back().fill(-1);
        pref.push_back(0);
        return nxt.size() - 1;
    }

    void insert(const string& word) {
        int v = 0;
        for (char ch : word) {
            int letter = ch - 'a';
            if (nxt[v][letter] == -1) {
                nxt[v][letter] = add_node();
            }
            v = nxt[v][letter];
            ++pref[v];
        }
    }

    int count_prefix(const string& prefix) {
        int v = 0;
        for (char ch : prefix) {
            int letter = ch - 'a';
            if (nxt[v][letter] == -1) {
                return 0;
            }
            v = nxt[v][letter];
        }
        return pref[v];
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    Trie trie;
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        trie.insert(word);
    }
    while (q--) {
        string prefix;
        cin >> prefix;
        cout << trie.count_prefix(prefix) << '\n';
    }
    return 0;
}
