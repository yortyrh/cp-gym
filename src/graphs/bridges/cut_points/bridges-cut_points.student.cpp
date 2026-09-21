#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Tarjan articulation points (discovery time / low-link DFS) ===
// Convert 1-based vertices to 0-based when reading.
// tin[v] = discovery time, low[v] = lowest tin reachable from v's subtree.
// Skip the parent on an undirected adjacency list.
// Non-root u is a cut vertex if some child v has low[v] >= tin[u].
// The DFS root is a cut vertex iff it has at least two DFS-tree children.
// Collect cut vertices in increasing 1-based order.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print k, then the k articulation points in increasing order (1-based).
    return 0;
}
