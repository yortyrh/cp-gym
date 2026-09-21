#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: breadth-first search distances on an unweighted graph ===
// Convert 1-based vertices to 0-based when reading.
// The graph is directed. Start a queue at vertex 0 (depot 1) with distance 0.
// When a vertex is first reached, its distance is final; enqueue it once.
// Unreached vertices stay at an infinity sentinel and print as -1.
// Do not use Dijkstra or DFS for distances.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges (1-based). Convert to 0-based at I/O.
    // Print n distances from vertex 1, space-separated, using -1 if unreachable.
    return 0;
}
