#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: edge connectivity by repeated max-flow ===
// Undirected simple graph. Put capacity 1 on each undirected edge (both residual directions).
// Fix source = 0 and compute max-flow to every other vertex; the minimum of those flows is
// the global min-cut size (edge connectivity). n is small.

signed main() {
    // === I/O ===
    // Read n, m, then m undirected edges u v (1-based).
    // Print the edge connectivity (0 if n <= 1).
    return 0;
}
