#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: max edge-disjoint paths via unit-capacity flow ===
// Directed graph. Each edge has capacity 1 (parallel edges add capacity).
// Max number of edge-disjoint paths from 1 to n equals max flow.
// Use residual DFS / Ford-Fulkerson or Dinic. Do not enumerate paths by hand.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges. Print the maximum number of edge-disjoint 1 -> n paths.
    return 0;
}
