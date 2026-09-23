#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Tarjan bridges (discovery time / low-link DFS) ===
// Convert 1-based vertices to 0-based when reading.
// tin[v] = discovery time, low[v] = lowest tin reachable via a back edge from v's subtree.
// Skip the parent on an undirected adjacency list.
// Tree edge u-v is a bridge iff low[v] > tin[u]. Store each bridge as (min, max).
// Sort the bridges before printing. Do not use max-flow.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges (1-based). Convert to 0-based at I/O.
    // Print k, then k lines u v (1-based, u < v) in lexicographic order.
    return 0;
}
