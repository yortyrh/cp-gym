#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Hungarian (Kuhn-Munkres) min-cost assignment ===
// Square n x n cost matrix. Dual potentials u[i], v[j] grow a tight equality subgraph.
// Each row is added in turn; reduce minv by delta and flip the alternating path stored in way[].
// The minimum assignment cost is -v[0] after n phases. n is small; do not enumerate n! permutations.

signed main() {
    // === I/O ===
    // Read n, then an n x n matrix of costs.
    // Print the minimum cost of a perfect assignment.
    return 0;
}
