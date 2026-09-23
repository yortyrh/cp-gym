#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Prim MST (binary heap) ===
// Undirected weighted graph. Grow the tree from vertex 1.
// Keep a min-heap of (weight, neighbour) leaving the connected set.
// Skip heap entries whose neighbour is already connected.
// Vertices are 1-based. Do not sort the full edge list (Kruskal) for this exercise.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges u v w.
    // Print the MST total weight grown from vertex 1, or -1 if disconnected.
    return 0;
}
