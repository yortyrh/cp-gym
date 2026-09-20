#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: unbounded knapsack DP (minimum coins) ===
// dp[x] = fewest coins that sum to x. dp[0] = 0. Each coin relaxes dp left to right.
// Print -1 if amount is impossible. Do not use greedy coin selection.
// Arrays for the coin list and dp are 0-based.

signed main() {
    // === I/O ===
    // Read n and amount, then n positive coin denominations.
    // Print the minimum number of coins that sum to amount, or -1.
    return 0;
}
