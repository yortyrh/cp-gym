#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: push-relabel maximum flow ===
// Saturate every edge out of the source and set height[source] = n. Vertices hold excess flow.
// Push along residual edges with height[u] == height[v] + 1. If excess remains, relabel u to
// min height of a residual neighbour plus one, then try again. The flow value is excess[sink].

signed main() {
    // === I/O ===
    // Read n, m, s, t (1-based source and sink), then m directed edges u v capacity.
    // Print the maximum flow from s to t.
    return 0;
}
