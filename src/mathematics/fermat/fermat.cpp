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

int mod_pow(int base, int exponent, int modulus) {
    int result = 1 % modulus;
    base %= modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = result * base % modulus;
        }
        base = base * base % modulus;
        exponent >>= 1;
    }
    return result;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int a, p;
        cin >> a >> p;
        cout << mod_pow(a, p - 2, p) << '\n';
    }
    return 0;
}
