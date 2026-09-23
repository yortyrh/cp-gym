#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Held-Karp bitmask DP (dp[mask][v]) ===
// Cities are 0-based internally; city 1 in the statement is index 0.
// dp[mask][v] = cheapest path from 0 that visits mask and ends at v.
// Start with dp[1][0] = 0. Close the tour with d[v][0]. Do not enumerate n!.

signed main() {
    // === I/O ===
    // Read n and the n x n distance matrix. Print the minimum Hamiltonian
    // circuit cost starting and ending at city 1.
    return 0;
}
