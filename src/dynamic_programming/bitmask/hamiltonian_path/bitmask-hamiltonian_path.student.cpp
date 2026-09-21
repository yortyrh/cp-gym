#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bitmask DP counting Hamiltonian paths ===
// dp[mask][v] = ways to visit mask and end at v. Initialize dp[1<<s][s] = 1
// for every start s. Transition along an edge v -> u with u not in mask.
// Sum dp[full][*]. Modulo 1e9+7. Do not close the tour and do not backtrack.

signed main() {
    // === I/O ===
    // Read n and the adjacency matrix. Print the number of Hamiltonian
    // paths modulo 1000000007.
    return 0;
}
