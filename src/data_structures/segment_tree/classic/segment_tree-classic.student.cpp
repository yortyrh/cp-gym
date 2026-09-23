#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: iterative segment tree (point assign, range sum) ===
// Implement a 1-based iterative segment tree.
// Leaves occupy tree[n .. 2n). For i = n-1 .. 1, tree[i] = tree[2i] + tree[2i+1].
// Required operations:
//   set(i, v)       — point-assign 1-based index i to value v, then rebuild parents
//   range_sum(l, r) — inclusive sum a[l] + ... + a[r]
// Convert a 1-based inclusive query [l, r] to a 0-based half-open walk [l-1, r).
// Do not rebuild the whole tree on every query. Do not use a Fenwick tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build the iterative segment tree from the array.
    // For each query:
    //   type 1 i v  → set a[i] to v
    //   type 2 l r  → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
