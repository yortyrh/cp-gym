#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: solve Ax = b by Gaussian elimination and back substitution ===
// Append b as an extra column. Eliminate as usual.
// If rank < n or a diagonal pivot is ~0, print -1.
// Back-substitute from row n-1 down to 0.

signed main() {
    // === I/O ===
    // Read n, A, and b. Print the unique solution with 10 decimals, or -1.
    return 0;
}
