#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: connected components by DFS ===
// Convert 1-based vertices to 0-based when reading.
// The graph is undirected. Scan vertices 0..n-1.
// Each unvisited vertex starts a new component id (1, 2, ...).
// DFS (or BFS) from that vertex paints every reachable vertex with the same id.
// Do not use disjoint-set union for this exercise.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print k, then n component ids for vertices 1..n.
    return 0;
}
