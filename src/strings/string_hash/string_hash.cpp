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
    int n, q;
    string s;
    cin >> n >> q >> s;
    const int base = 911382323;
    const int mod = 1000000007;
    vector<int> power(n + 1, 1);
    vector<int> prefix(n + 1);
    for (int i = 0; i < n; ++i) {
        power[i + 1] = power[i] * base % mod;
        int value = static_cast<unsigned char>(s[i]) + 1;
        prefix[i + 1] = (prefix[i] * base + value) % mod;
    }
    auto get_hash = [&](int begin, int end) {
        int value = prefix[end] - prefix[begin] * power[end - begin] % mod;
        if (value < 0) {
            value += mod;
        }
        return value;
    };
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (r1 - l1 != r2 - l2) {
            cout << "NO\n";
            continue;
        }
        if (get_hash(l1 - 1, r1) == get_hash(l2 - 1, r2)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
