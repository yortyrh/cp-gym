#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree on a coordinate-compressed universe ===
// Values, query bounds, and updates are in [1, 10^9]. Read all queries first,
// collect every integer that appears, compress to ranks 1..k, then Fenwick on k.
// Same operations as frequency counting, but never allocate a tree of size 10^9.
// Do not use std::map as the Fenwick tree for this exercise.

signed main() {
    // === I/O ===
    // Read q, then q queries (no universe size n):
    //   type 1 x   → insert one occurrence of x
    //   type 2 x   → erase one occurrence of x (x is present)
    //   type 3 l r → print how many stored values lie in [l, r]
    // Write answers to stdout.
    return 0;
}
