#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: extended Euclidean algorithm ===
// Keep old/current remainder and coefficients x, y.
// remainder := old - quotient * remainder, and the same for x and y.
// If the final gcd is negative, negate g, x, and y.
// Any valid Bézout triple with g >= 0 is accepted by the sample (the reference uses the iterative table).

signed main() {
    // === I/O ===
    // Read q pairs (a, b). Print g x y with a*x + b*y = g, g >= 0.
    return 0;
}
