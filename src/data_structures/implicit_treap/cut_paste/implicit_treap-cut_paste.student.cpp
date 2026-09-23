#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: implicit treap cut-and-merge ===
// Build an implicit treap on a[1..n]. Each operation (l, r, p):
//   split off the prefix of length l-1
//   split off the middle of length r-l+1 (the cut piece)
//   remaining = prefix + suffix
//   split remaining after p elements, then merge left + cut + right
// p = 0 puts the piece at the front; p = remaining length puts it at the back.
// After all operations, print the sequence (inorder traversal).
// Do not move the subarray in O(n) per query.

signed main() {
    // === I/O ===
    // Read n, q and the initial sequence a[1..n].
    // For each of q operations, read l r p and cut [l, r], then paste after
    // the first p elements of what remains.
    // Print the final sequence as n space-separated integers.
    return 0;
}
