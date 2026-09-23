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

int gcd_abs(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    while (b != 0) {
        int next = a % b;
        a = b;
        b = next;
    }
    return a;
}

int lcm_pos(int a, int b) {
    return a / gcd_abs(a, b) * b;
}

int carmichael_lambda(int n) {
    if (n == 1) {
        return 1;
    }
    int result = 1;
    int value = n;
    int exponent = 0;
    while (value % 2 == 0) {
        value /= 2;
        ++exponent;
    }
    if (exponent == 1) {
        result = lcm_pos(result, 1);
    } else if (exponent == 2) {
        result = lcm_pos(result, 2);
    } else if (exponent >= 3) {
        int part = 1;
        for (int i = 0; i < exponent - 2; ++i) {
            part *= 2;
        }
        result = lcm_pos(result, part);
    }
    for (int p = 3; p <= value / p; ++p) {
        if (value % p == 0) {
            int exp = 0;
            while (value % p == 0) {
                value /= p;
                ++exp;
            }
            int part = p - 1;
            for (int i = 0; i < exp - 1; ++i) {
                part *= p;
            }
            result = lcm_pos(result, part);
        }
    }
    if (value > 1) {
        result = lcm_pos(result, value - 1);
    }
    return result;
}

int mod_pow(int base, int exponent, int modulus) {
    int result = 1 % modulus;
    base %= modulus;
    if (base < 0) {
        base += modulus;
    }
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
        int a, n;
        cin >> a >> n;
        if (n <= 1) {
            cout << 0 << '\n';
            continue;
        }
        int reduced = a % n;
        if (reduced < 0) {
            reduced += n;
        }
        if (gcd_abs(reduced, n) != 1) {
            cout << 0 << '\n';
            continue;
        }
        int value = mod_pow(reduced, carmichael_lambda(n), n);
        cout << (value == 1 ? 1 : 0) << '\n';
    }
    return 0;
}
