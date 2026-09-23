#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 0-1 BFS (deque shortest paths) ===
// Every directed edge weight is 0 or 1. dist[s] = 0.
// Pop from the front of a deque. Weight 0: push_front the neighbour.
// Weight 1: push_back. This is O(n + m). Do not use a binary-heap Dijkstra here.
// Vertices are 1-based.

signed main() {
    // === I/O ===
    // Read n, m, s and m directed edges u v w with w in {0, 1}.
    // Print n tokens: dist[1..n], or INF if unreachable, space-separated.
    return 0;
}
