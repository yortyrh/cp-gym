#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Tarjan offline LCA ===
// Keep a local DSU (find with path compression, unite by size). DFS the tree.
// After finishing a child, unite it with the current vertex and set the DSU ancestor to the vertex.
// When both endpoints of a query are visited, the LCA is ancestor[find(other)].
// Do not include a library DSU header; keep the DSU inline.

signed main() {
    // === I/O ===
    // Read n, q, then n-1 tree edges (1-based, root 1), then q queries u v.
    // Print the 1-based lowest common ancestor of u and v for each query.
    return 0;
}
