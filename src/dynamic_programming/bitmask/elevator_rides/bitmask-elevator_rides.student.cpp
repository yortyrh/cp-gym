#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bitmask DP (permutations to subsets) ===
// For every mask S store {rides, last_weight}. Empty set uses 1 empty ride
// of weight 0. To form S, try each person p in S coming from S without p.
// If last_weight + w[p] <= x, add p to the last ride; else start a new ride.
// Do not search n! permutations.

signed main() {
    // === I/O ===
    // Read n, x and n weights. Print the minimum number of rides.
    return 0;
}
