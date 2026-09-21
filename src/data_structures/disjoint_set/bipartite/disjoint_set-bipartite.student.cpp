#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: DSU with parity (bipartite union-find) ===
// Store parent, size, and XOR-parity to the parent/root.
// find(v) compresses the path and accumulates parity so parity[v] is v's color
// relative to the root.
// add_edge(u, v) must place u and v in opposite colors.
// If they are already in the same component and already have the same parity,
// the graph is no longer bipartite. A self-loop is an odd cycle.
// Do not BFS/DFS to recolor after every edge.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges u v.
    // After each edge, print YES if the graph is still bipartite, otherwise NO.
    return 0;
}
