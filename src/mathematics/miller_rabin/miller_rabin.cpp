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

int mod_mul(int lhs, int rhs, int modulus) {
    return static_cast<__int128>(lhs) * rhs % modulus;
}

int mod_pow(int base, int exponent, int modulus) {
    int result = 1 % modulus;
    base %= modulus;
    while (exponent > 0) {
        if (exponent & 1) {
            result = mod_mul(result, base, modulus);
        }
        base = mod_mul(base, base, modulus);
        exponent >>= 1;
    }
    return result;
}

bool miller_rabin_check(int value, int witness, int odd_part, int twos) {
    int x = mod_pow(witness, odd_part, value);
    if (x == 1 || x == value - 1) {
        return false;
    }
    for (int round = 1; round < twos; ++round) {
        x = mod_mul(x, x, value);
        if (x == value - 1) {
            return false;
        }
    }
    return true;
}

bool is_prime(int value) {
    if (value < 2) {
        return false;
    }
    int small_primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (int prime : small_primes) {
        if (value == prime) {
            return true;
        }
        if (value % prime == 0) {
            return false;
        }
    }
    int odd_part = value - 1;
    int twos = 0;
    while ((odd_part & 1) == 0) {
        odd_part >>= 1;
        ++twos;
    }
    int witnesses[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int witness : witnesses) {
        if (witness % value == 0) {
            continue;
        }
        if (miller_rabin_check(value, witness, odd_part, twos)) {
            return false;
        }
    }
    return true;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << (is_prime(n) ? "YES" : "NO") << '\n';
    }
    return 0;
}
