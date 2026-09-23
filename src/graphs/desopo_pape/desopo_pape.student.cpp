#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: D'Esopo-Pape (deque SPFA) ===
// Directed graph, weights may be negative, no negative cycle from s.
// state: 2 = never seen, 1 = in deque, 0 = already processed.
// New vertex: push_back. Improved vertex that was already processed: push_front.
// If it is already in the deque (state 1), only update dist.
// Vertices are 1-based. Do not use a binary-heap Dijkstra for this exercise.

signed main() {
    // === I/O ===
    // Read n, m, s and m directed edges u v w.
    // Print n tokens: dist[1..n], or INF if unreachable, space-separated.
    return 0;
}
