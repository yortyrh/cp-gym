#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: expected value DP ===
// Fair f-sided die, faces 1..f. Start at sum 0. Stop when sum >= n.
// E[x] = expected extra rolls from current sum x. E[x] = 0 for x >= n.
// E[x] = 1 + (1/f) * sum_{d=1..f} E[x+d]  (treat E[>=n] as 0).
// Fill x = n-1 down to 0. Print E[0] as P * Q^{-1} modulo 1e9+7.

signed main() {
    // === I/O ===
    // Read n and f. Print E[0] modulo 1000000007.
    return 0;
}
