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

struct StringHash {
    int mod;
    vector<int> power;
    vector<int> prefix;

    StringHash(const string& text, int base = 911382323, int modulus = 1000000007)
        : mod(modulus), power(text.size() + 1, 1), prefix(text.size() + 1) {
        int n = text.size();
        for (int i = 0; i < n; ++i) {
            power[i + 1] = power[i] * base % mod;
            int value = static_cast<unsigned char>(text[i]) + 1;
            prefix[i + 1] = (prefix[i] * base + value) % mod;
        }
    }

    int get(int begin, int end) const {
        int value = prefix[end] - prefix[begin] * power[end - begin] % mod;
        if (value < 0) {
            value += mod;
        }
        return value;
    }
};

signed main() {
    string text, pattern;
    cin >> text >> pattern;
    int n = text.size();
    int m = pattern.size();
    StringHash text_hash(text);
    StringHash pattern_hash(pattern);
    int target = pattern_hash.get(0, m);
    vector<int> matches;
    for (int begin = 0; begin + m <= n; ++begin) {
        if (text_hash.get(begin, begin + m) == target && text.compare(begin, m, pattern) == 0) {
            matches.push_back(begin);
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
