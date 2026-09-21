#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Hierholzer Eulerian path in a directed graph ===
// Count in/out degrees. Exactly 0 or 1 vertex with out = in+1 (start), and 0 or 1 with in = out+1.
// Walk unused outgoing edges on a stack; prepend a vertex when it has no unused edges left.
// Reverse the recorded path. If its length is not m+1, the graph is disconnected: print NO.

signed main() {
    // === I/O ===
    // Read n, m, then m directed edges u v (1-based).
    // Print NO, or YES and a vertex sequence of length m+1.
    return 0;
}
