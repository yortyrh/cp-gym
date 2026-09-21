#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Gaussian elimination with partial pivoting ===
// Partial pivoting: largest |entry| in the current column, from pivot_row down.
// If the pivot is < 1e-9, set det = 0 and skip the column (do not increment pivot_row).
// Each swap multiplies det by -1. Multiply det by the pivot, then eliminate below.
// rank is the final pivot_row count.

signed main() {
    // === I/O ===
    // Read n and an n by n matrix. Print rank, then det with 10 decimal places.
    return 0;
}
