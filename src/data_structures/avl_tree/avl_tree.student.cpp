#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: AVL tree (height-balanced BST with subtree sizes) ===
// Unique keys. After insert/erase, rotations restore |height(L) - height(R)| <= 1.
// Store subtree sizes so the k-th order statistic is O(log n).
// Required operations:
//   insert(x) — add x if missing
//   erase(x)  — remove x if present
//   kth(k)    — 1-based k-th smallest, or -1 if k is out of range
// Do not rebuild a sorted vector on every type-3 query.

signed main() {
    // === I/O ===
    // Read q operations from stdin.
    //   type 1 x  → insert x
    //   type 2 x  → erase x
    //   type 3 k  → print the k-th smallest value, or -1
    // Write answers to stdout.
    return 0;
}
