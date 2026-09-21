#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: implicit treap with lazy reverse ===
// Build an implicit treap on a[1..n]. Each node also stores a reverse flag.
// push(t): if t->rev, swap children and toggle each child's flag, then clear t->rev.
// Call push before split/merge inspect children.
// Reverse [l, r]: split out the middle, toggle its reverse flag, merge back.
// Range sum [l, r]: split out the middle, print its sum (reverse does not change
// sums), merge back. Do not reverse the array in O(n) per query.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // For each operation:
    //   type 1 l r  → reverse the inclusive subarray [l, r]
    //   type 2 l r  → print the inclusive range sum
    // Write answers to stdout.
    return 0;
}
