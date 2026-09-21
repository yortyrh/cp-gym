#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Edmonds-Karp maximum flow ===
// Residual graph with forward/backward edges. Repeatedly BFS a shortest residual path from s to t.
// Augment by the bottleneck capacity and update both directions. Stop when t is unreachable.
// Vertices are 0-based internally. Do not DFS-augment; BFS keeps the path length shortest.

signed main() {
    // === I/O ===
    // Read n, m, s, t (1-based source and sink), then m directed edges u v capacity.
    // Print the maximum flow from s to t.
    return 0;
}
