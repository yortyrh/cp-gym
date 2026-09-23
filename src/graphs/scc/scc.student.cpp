#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Tarjan strongly connected components ===
// Convert 1-based vertices to 0-based when reading.
// The graph is directed. One DFS with tin, low, and a stack of the current path.
// When low[v] == tin[v], pop until v: that slice is one SCC.
// Number components 1..k by increasing smallest vertex in each component.
// Kosaraju is allowed if the same numbering rule is used.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges (1-based). Convert to 0-based at I/O.
    // Print k, then n component ids for vertices 1..n.
    return 0;
}
