#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: segment tree on compressed values (range k-th smallest) ===
// Compress distinct a[i] onto ranks. Build a segment tree over the rank axis.
// Each node stores the sorted 1-based positions whose values lie in that rank segment.
// To answer (l, r, k):
//   count = how many positions in the left child fall in inclusive [l, r]
//   if k <= count go left, else go right with k -= count
// The leaf you reach is the k-th smallest value. Do not sort every query range.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n] from stdin.
    // Compress values and build the segment tree of positions.
    // For each query l r k, print the k-th smallest on inclusive [l, r].
    // Write answers to stdout.
    return 0;
}
