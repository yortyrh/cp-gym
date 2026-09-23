#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Sprague-Grundy on a subtraction game ===
// One pile: you may subtract a value from the given set, staying non-negative.
// g[0] = 0. g[x] = mex of g[x - d] over allowed d <= x.
// Several piles: xor the Grundy numbers. Nonzero xor means First wins.

signed main() {
    // === I/O ===
    // Read n, s, then s subtraction values, then n pile sizes.
    // Print First or Second.
    return 0;
}
