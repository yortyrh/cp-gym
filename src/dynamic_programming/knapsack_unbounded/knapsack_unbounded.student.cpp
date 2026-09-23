#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: unbounded knapsack (iterate capacity increasing) ===
// dp[w] = max value with capacity at most w. Each item may be used any
// number of times: for each item, loop capacity from weight up to W.
// Arrays are 0-based. Do not iterate capacity downward (that is 0-1).

signed main() {
    // === I/O ===
    // Read n, W, then n lines of weight and value.
    // Print the maximum total value whose weights sum to at most W.
    return 0;
}
