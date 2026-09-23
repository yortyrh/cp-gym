#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: lazy segment tree (range add, range sum) ===
// Implement a 1-based segment tree with lazy range-add tags.
// Each node stores the sum of its segment. A pending add is applied to the node
// immediately and pushed to children only when the node is split.
// Required operations:
//   range_add(l, r, v) — add v to every index in inclusive [l, r]
//   range_sum(l, r)    — sum of a[l] + ... + a[r]
// Do not loop over the range. Do not use two Fenwick trees for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build the lazy segment tree from the array.
    // For each query:
    //   type 1 l r v  → add v to inclusive [l, r]
    //   type 2 l r    → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
