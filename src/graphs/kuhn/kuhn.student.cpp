#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kuhn bipartite matching (DFS augmenting paths) ===
// Left vertices 0..n-1, right vertices 0..m-1. match_right[r] is the matched left vertex or -1.
// From each free left vertex, DFS unused right vertices and try to rematch their current partner.
// Repeat a DFS from every left vertex. The matching size is the number of right vertices with a partner.
// Do not build a flow network.

signed main() {
    // === I/O ===
    // Read n, m, e, then e left-right edges (1-based).
    // Print the size of a maximum matching.
    return 0;
}
