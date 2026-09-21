#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: depth-first search from a source ===
// Convert 1-based vertices to 0-based when reading.
// Build an undirected adjacency list; neighbours keep input order.
// Mark a vertex when first entering it, then recurse along unused edges.
// Record the preorder (discovery) sequence. Start at vertex 0 (chamber 1).
// Unreachable vertices must not appear. Do not use BFS.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print the 1-based DFS discovery order from vertex 1, space-separated.
    return 0;
}
