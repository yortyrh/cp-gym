#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sparse table (disjoint power-of-two covering) ===
// st[k][i] = sum of 2^k elements starting at 1-based index i.
// Cover [l, r] from largest k down: if 2^k fits, add st[k][l] and advance l.
// Sum is not idempotent, so do not use two overlapping intervals.
// Do not use prefix sums, Fenwick, or a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the array a[1..n].
    // For each query l r, print a[l] + ... + a[r] followed by a newline.
    return 0;
}
