#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bitset Floyd / transitive closure ===
// reach[i] is a bitset of nodes reachable from i (including i).
// For k = 1..n, for each i that already reaches k: reach[i] |= reach[k].
// Answer queries with reach[u].test(v). Do not run a separate BFS per query.

signed main() {
    // === I/O ===
    // Read n, m, q, then m directed edges, then q pairs u v.
    // Print 1 if u can reach v, else 0.
    return 0;
}
