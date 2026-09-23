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

struct Egcd {
    int g, x, y;
};

Egcd extended_gcd(int lhs, int rhs) {
    int old_remainder = lhs;
    int remainder = rhs;
    int old_x = 1;
    int x = 0;
    int old_y = 0;
    int y = 1;
    while (remainder != 0) {
        int quotient = old_remainder / remainder;
        int next_remainder = old_remainder - quotient * remainder;
        old_remainder = remainder;
        remainder = next_remainder;
        int next_x = old_x - quotient * x;
        old_x = x;
        x = next_x;
        int next_y = old_y - quotient * y;
        old_y = y;
        y = next_y;
    }
    if (old_remainder < 0) {
        old_remainder = -old_remainder;
        old_x = -old_x;
        old_y = -old_y;
    }
    return {old_remainder, old_x, old_y};
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int value, modulus;
        cin >> value >> modulus;
        Egcd bez = extended_gcd(value, modulus);
        if (bez.g != 1) {
            cout << -1 << '\n';
            continue;
        }
        int inverse = bez.x % modulus;
        if (inverse < 0) {
            inverse += modulus;
        }
        cout << inverse << '\n';
    }
    return 0;
}
