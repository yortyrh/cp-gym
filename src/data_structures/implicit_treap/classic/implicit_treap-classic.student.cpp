#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: implicit treap (split/merge by size) ===
// Start with an empty sequence. Each node stores value, subtree size, subtree
// sum, and a random priority. split(t, k) cuts the first k positions.
// Insert at 1-based p: split(root, p-1), merge left + new node + right.
// Erase at p: split(root, p-1), split(right, 1), merge left + rest.
// Range sum [l, r]: split out the middle, read its sum, merge back.
// Expected O(log n) per operation. Do not rebuild the whole array.

signed main() {
    // === I/O ===
    // Read q. The sequence starts empty.
    // For each operation:
    //   type 1 p x  → insert x at 1-based position p
    //   type 2 p    → erase position p
    //   type 3 l r  → print the inclusive range sum
    // Write answers to stdout.
    return 0;
}
