#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: rerooting DP for tree distance sums ===
// First DFS: sz[v] and down[v] = sum of distances from v to vertices in its subtree.
// Second DFS: answer[child] = answer[parent] - sz[child] + (n - sz[child]).
// Print answer[v] for every vertex. Do not run a BFS from each vertex.

signed main() {
    // === I/O ===
    // Read n, then n-1 tree edges (1-based).
    // Print n integers: for each vertex, the sum of distances to all vertices.
    return 0;
}
