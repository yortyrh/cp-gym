#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: successive shortest paths min-cost flow ===
// Residual edges store capacity and cost (backward cost is negated). Reduced costs use potentials.
// Dijkstra finds a cheapest residual path; augment by the bottleneck; update potentials by distances.
// Repeat until flow_limit is reached or the sink is unreachable. Print achieved flow and its cost.

signed main() {
    // === I/O ===
    // Read n, m, s, t, flow_limit, then m directed edges u v capacity cost.
    // Print the sent flow and its total cost.
    return 0;
}
