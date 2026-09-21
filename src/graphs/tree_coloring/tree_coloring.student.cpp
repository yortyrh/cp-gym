#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: tree DP for proper k-colorings ===
// Adjacent vertices must receive different colors. Root at 0: the root has `colors` choices,
// every other vertex has `colors-1` choices (differ from its parent). DFS the tree and multiply.
// The count is colors * (colors-1)^{n-1} on any tree. Do not enumerate colorings.

signed main() {
    // === I/O ===
    // Read n, k, then n-1 tree edges (1-based).
    // Print the number of proper k-colorings.
    return 0;
}
