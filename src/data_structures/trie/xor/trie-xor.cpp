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

struct BinaryTrie {
    static constexpr int bits = 30;
    vector<array<int, 2>> nxt;

    BinaryTrie() { nxt.push_back({-1, -1}); }

    void insert(int x) {
        int v = 0;
        for (int b = bits; b >= 0; --b) {
            int bit = (x >> b) & 1;
            if (nxt[v][bit] == -1) {
                nxt[v][bit] = nxt.size();
                nxt.push_back({-1, -1});
            }
            v = nxt[v][bit];
        }
    }

    int max_xor(int x) {
        int v = 0;
        int result = 0;
        int value = 1;
        for (int i = 0; i < bits; ++i) {
            value += value;
        }
        for (int b = bits; b >= 0; --b) {
            int bit = (x >> b) & 1;
            int want = bit ^ 1;
            if (nxt[v][want] != -1) {
                result += value;
                v = nxt[v][want];
            } else {
                v = nxt[v][bit];
            }
            value /= 2;
        }
        return result;
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    BinaryTrie trie;
    for (int x : a) {
        trie.insert(x);
    }
    int best = 0;
    for (int x : a) {
        best = max(best, trie.max_xor(x));
    }
    cout << best << '\n';
    return 0;
}
