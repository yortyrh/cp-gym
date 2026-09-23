#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: longest path in a DAG (topo DP) ===
// dp[v] = longest path (edge count) ending at v.
// Process nodes in topological order. Relax each edge u -> v:
//   dp[v] = max(dp[v], dp[u] + 1)
// The graph is a DAG. Print the global maximum dp value.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges. Print the longest path length in edges.
    return 0;
}
