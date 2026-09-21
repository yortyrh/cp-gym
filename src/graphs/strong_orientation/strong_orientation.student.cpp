#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: strong orientation of a bridgeless undirected graph ===
// Convert 1-based vertices to 0-based when reading.
// First DFS: tin/low bridges. A tree edge u-v is a bridge iff low[v] > tin[u].
// If any bridge exists, print NO.
// Second DFS: direct tree edges parent→child, back edges toward the earlier tin.
// Start each DFS at the smallest unvisited vertex. Skip the parent.
// Print directed pairs in the order the second DFS assigns them.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print NO, or YES followed by m directed 1-based pairs.
    return 0;
}
