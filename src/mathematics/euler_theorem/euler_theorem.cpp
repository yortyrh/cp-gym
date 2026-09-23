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
    if (b < 0) {
        b = -b;
    }
    while (b != 0) {
        int next = a % b;
        a = b;
        b = next;
    }
    return a;
}

int euler_phi(int n) {
    int result = n;
    int value = n;
    for (int p = 2; p <= value / p; ++p) {
        if (value % p == 0) {
            while (value % p == 0) {
                value /= p;
            }
            result -= result / p;
        }
    }
    if (value > 1) {
        result -= result / value;
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
        if (gcd_abs(a, n) != 1) {
            cout << -1 << '\n';
            continue;
        }
        int phi = euler_phi(n);
        cout << mod_pow(a, phi - 1, n) << '\n';
    }
    return 0;
}
