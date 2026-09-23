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
    return static_cast<__int128>(lhs) * rhs % modulus;
}

pair<int, int> fib_pair(int n, int modulus) {
    if (n == 0) {
        return {0, 1 % modulus};
    }
    auto [f_k, f_k1] = fib_pair(n >> 1, modulus);
    int two_f_k1 = mod_mul(2 % modulus, f_k1, modulus);
    int inner = two_f_k1 >= f_k ? two_f_k1 - f_k : two_f_k1 + (modulus - f_k);
    int c = mod_mul(f_k, inner, modulus);
    int d = (mod_mul(f_k, f_k, modulus) + mod_mul(f_k1, f_k1, modulus)) % modulus;
    if ((n & 1) == 0) {
        return {c, d};
    }
    return {d, (c + d) % modulus};
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, m;
        cin >> n >> m;
        cout << fib_pair(n, m).first << '\n';
    }
    return 0;
}
