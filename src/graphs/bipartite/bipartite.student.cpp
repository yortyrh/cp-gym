#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bipartite check by 2-coloring (BFS) ===
// Convert 1-based vertices to 0-based when reading.
// The graph is undirected. color[v] is -1 (unseen), 0, or 1.
// For every uncolored start, BFS with color 0. Neighbours get the opposite color.
// Same color on an edge means an odd cycle: print NO.
// Isolated vertices keep color 0. Print colors as 1 and 2. Do not use matching.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print YES and n colors (1 or 2), or NO.
    return 0;
}
