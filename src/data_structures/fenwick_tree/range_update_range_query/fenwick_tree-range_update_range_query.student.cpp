#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: two Fenwick trees (range update, range query) ===
// Maintain two 1-based Fenwick trees B1 and B2 so that
//   range_add(l, r, v) updates both trees
//   prefix(i) = B1.prefix(i) * i - B2.prefix(i)
//   range_sum(l, r) = prefix(r) - prefix(l - 1)
// Do not use a segment tree with lazy propagation for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // Build the dual Fenwick structure from the array.
    // For each query:
    //   type 1 l r v → add v to every element in [l, r]
    //   type 2 l r   → print the sum of [l, r]
    // Write answers to stdout.
    return 0;
}
