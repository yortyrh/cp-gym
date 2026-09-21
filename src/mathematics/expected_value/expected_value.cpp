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

const int mod = 1e9 + 7;

int modpow(int a, int e) {
    int r = 1;
    a %= mod;
    while (e > 0) {
        if (e & 1) {
            r = r * a % mod;
        }
        a = a * a % mod;
        e /= 2;
    }
    return r;
}

signed main() {
    int n, f;
    cin >> n >> f;
    int inv_f = modpow(f, mod - 2);
    vector<int> E(n + 1);
    for (int x = n - 1; x >= 0; --x) {
        int sum = 0;
        for (int d = 1; d <= f; ++d) {
            int nxt = x + d;
            if (nxt < n) {
                sum += E[nxt];
            }
        }
        sum %= mod;
        E[x] = (1 + sum * inv_f) % mod;
    }
    cout << E[0] << '\n';
    return 0;
}
