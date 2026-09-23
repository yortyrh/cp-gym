#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Newton–Raphson root finding ===
// Find the positive root of f(x) = x^2 - n. f'(x) = 2x.
// Start at 1. Iterate x := x - f(x)/f'(x) at most 40 times, stopping when
// |Δx| < 1e-10. Do not call std::sqrt.

signed main() {
    // === I/O ===
    // Read n.
    // Print sqrt(n) with exactly 10 digits after the decimal point.
    return 0;
}
