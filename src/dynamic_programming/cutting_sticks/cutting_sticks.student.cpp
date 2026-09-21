#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: interval DP (minimum cost to cut a stick) ===
// Add the ends 0 and L to the cut list, sort, and unique.
// cost[l][r] = min cost to cut every remaining point strictly inside
// points[l] .. points[r]. Cutting the piece costs points[r] - points[l].
// Fill by increasing span. Arrays are 0-based. This is O(m^3).

signed main() {
    // === I/O ===
    // Read L, m, then m cut positions.
    // Print the minimum total cutting cost.
    return 0;
}
