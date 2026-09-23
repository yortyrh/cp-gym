#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 0-1 knapsack DP over value (minimize weight) ===
// W is too large for dp[W]. Values are small: let S be the sum of all values.
// dp[v] = minimum weight needed to obtain value exactly v (INF if impossible).
// Process items decreasing in v. Answer = max v with dp[v] <= W.
// Arrays are 0-based. Do not allocate an array of size W.

signed main() {
    // === I/O ===
    // Read n, W, then n lines of weight and value.
    // Print the maximum total value whose weights sum to at most W.
    return 0;
}
