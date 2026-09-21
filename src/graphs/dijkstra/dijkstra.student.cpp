#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Dijkstra (non-negative binary heap) ===
// Build a 1-based adjacency list of directed edges. All weights are non-negative.
// dist[s] = 0. A min-heap stores (distance, vertex). Skip stale heap entries
// whose distance is not the current dist[v]. Relax outgoing edges.
// Do not use Bellman-Ford for this exercise.

signed main() {
    // === I/O ===
    // Read n, m, s and m directed edges u v w (w >= 0).
    // Print n tokens: dist[1..n], or INF if unreachable, space-separated.
    return 0;
}
