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
    int n, length;
    cin >> n >> length;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<string> next(n);
    for (int pos = length - 1; pos >= 0; --pos) {
        vector<int> freq(26);
        for (int i = 0; i < n; ++i) {
            ++freq[words[i][pos] - 'a'];
        }
        for (int letter = 1; letter < 26; ++letter) {
            freq[letter] += freq[letter - 1];
        }
        for (int i = n - 1; i >= 0; --i) {
            int letter = words[i][pos] - 'a';
            next[--freq[letter]] = words[i];
        }
        words.swap(next);
    }
    for (int i = 0; i < n; ++i) {
        cout << words[i] << '\n';
    }
    return 0;
}
