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

int mod_mul(int lhs, int rhs, int modulus) {
    lhs %= modulus;
    if (lhs < 0) {
        lhs += modulus;
    }
    rhs %= modulus;
    if (rhs < 0) {
        rhs += modulus;
    }
    int product = 0;
    while (rhs > 0) {
        if (rhs & 1) {
            product += lhs;
            if (product >= modulus) {
                product -= modulus;
            }
        }
        lhs += lhs;
        if (lhs >= modulus) {
            lhs -= modulus;
        }
        rhs >>= 1;
    }
    return product;
}

int mod_pow(int base, int exponent, int modulus) {
    base %= modulus;
    if (base < 0) {
        base += modulus;
    }
    int result = 1 % modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = mod_mul(result, base, modulus);
        }
        base = mod_mul(base, base, modulus);
        exponent >>= 1;
    }
    return result;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int base, exponent, modulus;
        cin >> base >> exponent >> modulus;
        cout << mod_pow(base, exponent, modulus) << '\n';
    }
    return 0;
}
