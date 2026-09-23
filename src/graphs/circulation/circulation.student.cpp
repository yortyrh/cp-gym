#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: feasible circulation with vertex demands ===
// demand[v] > 0 means v must receive that much net flow; demand[v] < 0 means v supplies |demand[v]|.
// Sum of demands must be 0. Attach a super-source to supplies and a super-sink to demands, then
// check whether max-flow equals the total demand. Original edges keep their capacities.

signed main() {
    // === I/O ===
    // Read n, m, then n demands, then m directed edges u v capacity (1-based vertices).
    // Print YES if a feasible circulation exists, otherwise NO.
    return 0;
}
