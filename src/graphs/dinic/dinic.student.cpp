#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Dinic maximum flow ===
// Residual graph with forward/backward edges. BFS builds a level graph from the source.
// DFS then sends blocking flow only along edges that go one level forward (current-edge pointers).
// Repeat until the sink is unreachable in the residual graph. Vertices are 0-based internally.

signed main() {
    // === I/O ===
    // Read n, m, s, t (1-based source and sink), then m directed edges u v capacity.
    // Print the maximum flow from s to t.
    return 0;
}
