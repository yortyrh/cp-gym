#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Euler's totient from prime factorization ===
// Trial-divide n. For each prime p, while p divides n, strip it, then result -= result / p.
// If a prime > sqrt remains, apply the same formula once.
// phi(1) = 1.

signed main() {
    // === I/O ===
    // Read q values of n. Print phi(n) for each.
    return 0;
}
