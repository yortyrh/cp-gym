#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kruskal MST (sort edges, union-find) ===
// Undirected weighted graph. Sort all edges by weight.
// Keep an inline DSU (union by size, path compression); do not include a DSU header.
// Add an edge when unite() joins two components. Stop at n-1 edges.
// Vertices are 1-based. Do not grow a Prim heap for this exercise.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges u v w.
    // Print the MST total weight, or -1 if the graph is disconnected.
    return 0;
}
