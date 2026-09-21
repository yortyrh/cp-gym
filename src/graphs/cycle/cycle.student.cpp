#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: directed cycle detection (three-color DFS) ===
// Convert 1-based vertices to 0-based when reading.
// The graph is directed. state: 0 white, 1 gray (on the stack), 2 black.
// A neighbor with state 1 is a back edge, hence a directed cycle.
// Recurse from every white vertex. Do not treat the graph as undirected.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges (1-based). Convert to 0-based at I/O.
    // Print YES if a directed cycle exists, otherwise NO.
    return 0;
}
