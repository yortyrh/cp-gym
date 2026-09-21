#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: second-best MST (swap a non-tree edge) ===
// Build an MST with Kruskal and an inline DSU. Then, for every unused edge u-v,
// replace the heaviest MST edge on the tree path u...v (binary lifting).
// Keep the cheapest replacement that is strictly heavier than the MST.
// Vertices are 1-based. Print -1 if no such spanning tree exists.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges u v w.
    // Print the strictly second-best spanning-tree weight, or -1.
    return 0;
}
