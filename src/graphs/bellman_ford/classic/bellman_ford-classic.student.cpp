#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Bellman-Ford (single-source shortest paths) ===
// Store directed links as an edge list. dist[s] = 0, others INF.
// Relax every edge n-1 times (stop early if a pass changes nothing).
// Negative weights are allowed. This sample has no negative cycle.
// Vertices are 1-based. Do not use Dijkstra for this exercise.

signed main() {
    // === I/O ===
    // Read n, m, s and m directed edges u v w.
    // Print n tokens: dist[1..n], or INF if unreachable, space-separated.
    return 0;
}
