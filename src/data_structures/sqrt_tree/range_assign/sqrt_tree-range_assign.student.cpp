#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sqrt-tree mass-update analogue (lazy assignment on blocks) ===
// Split a[1..n] into blocks of length about sqrt(n). Store each block min.
// Range assign [l, r] = v:
//   whole blocks → store v as lazy and set the block min to v
//   partial blocks → push lazy, write elements, rebuild the block min
// Range min uses lazy/block min on whole blocks and scans leftover elements.
// Do not use a segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // For each query:
    //   type 1 l r v  → assign a[i] = v for every i in [l, r]
    //   type 2 l r    → print min(a[l..r]) followed by a newline
    // Write answers to stdout.
    return 0;
}
