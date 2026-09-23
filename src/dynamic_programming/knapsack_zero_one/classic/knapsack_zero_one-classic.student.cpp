#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 0-1 knapsack (iterate capacity decreasing) ===
// dp[w] = max value using capacity exactly-or-at-most w.
// Process items one by one. For each item (weight, value), loop capacity
// from W down to weight so the item is used at most once.
// Arrays are 0-based. Do not iterate capacity upward (that reuses the item).

signed main() {
    // === I/O ===
    // Read n, W, then n lines of weight and value.
    // Print the maximum total value whose weights sum to at most W.
    return 0;
}
