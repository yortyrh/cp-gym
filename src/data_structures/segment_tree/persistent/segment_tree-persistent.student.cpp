#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: persistent segment tree (point assign, range sum) ===
// Implement a persistent segment tree on 1-based indices.
// Version 0 is the initial array. Each point-assign copies O(log n) nodes
// and produces a new root. Old roots stay valid.
// Required operations:
//   update(root_k, i, v) — new root for a copy of version k with a[i] = v
//   query(root_k, l, r)  — inclusive sum on version k
// Do not copy the whole array. Versions are numbered 0, 1, 2, ... in creation order.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Build version 0 of the persistent segment tree.
    // For each query:
    //   type 1 k i v  → create the next version from version k by setting a[i] = v
    //   type 2 k l r  → print the inclusive sum of [l, r] on version k
    // Write answers to stdout.
    return 0;
}
