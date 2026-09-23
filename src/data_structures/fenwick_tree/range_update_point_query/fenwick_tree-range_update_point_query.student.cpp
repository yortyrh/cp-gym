#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree as a difference array (range update, point query) ===
// Implement a 1-based Fenwick tree over a difference array.
// Range add [l, r] += v becomes add(l, v) and add(r + 1, -v).
// Point query a[i] is prefix_sum(i).
// Do not loop over the range on every update. Do not use a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // Build the difference Fenwick tree from the array.
    // For each query:
    //   type 1 l r v → add v to every element in [l, r]
    //   type 2 i     → print a[i]
    // Write answers to stdout.
    return 0;
}
