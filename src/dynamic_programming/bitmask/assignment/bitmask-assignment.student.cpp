#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bitmask DP on subsets (dp[mask]) ===
// mask bit j = job j is taken. dp[mask] = ways to assign the first
// popcount(mask) people to those jobs. Transition: try each unused job
// compatible with the next person. Modulo 1e9+7. Do not backtrack over
// permutations.

signed main() {
    // === I/O ===
    // Read n and the n x n compatibility matrix. Print the number of
    // assignments modulo 1000000007.
    return 0;
}
