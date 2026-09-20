#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree (point update, range query) ===
// Implement a 1-based Fenwick tree (binary indexed tree).
// Index 0 is unused. tree[1] stores information about a[1].
// Required operations:
//   add(i, delta)   — point update at 1-based index i
//   prefix_sum(i)   — sum of a[1] + ... + a[i]
//   range_sum(l, r) — sum of a[l] + ... + a[r] = prefix_sum(r) - prefix_sum(l - 1)
// Do not rebuild prefix sums on every query. Do not use a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build the Fenwick tree from the array.
    // For each query:
    //   type 1 i v  → point-update index i to value v
    //   type 2 l r  → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
