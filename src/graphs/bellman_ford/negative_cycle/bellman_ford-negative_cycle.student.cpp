#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Bellman-Ford (negative-cycle reconstruction) ===
// Run Bellman-Ford from s for n passes on a directed edge list, storing parent[v]
// on every successful relaxation. Only relax through vertices with finite dist.
// If some distance still improves on pass n, a negative cycle is reachable from s.
// Walk parent n times to enter the cycle, then list it. Rotate so the printed
// sequence starts (and ends) at the smallest vertex id. Do not reverse the cycle.
// Vertices are 1-based.

signed main() {
    // === I/O ===
    // Read n, m, s and m directed edges u v w.
    // Print NO, or YES and one canonical simple negative cycle v1 ... vk v1.
    return 0;
}
