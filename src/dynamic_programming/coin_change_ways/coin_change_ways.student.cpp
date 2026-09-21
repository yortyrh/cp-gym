#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: unbounded knapsack DP (number of combinations) ===
// ways[x] = number of unordered combinations that sum to x, modulo 1e9+7.
// ways[0] = 1. Outer loop over coins, inner loop left to right, so each
// combination is counted once. Arrays are 0-based. Do not count permutations
// (that would loop amount in the outer loop).

signed main() {
    // === I/O ===
    // Read n and amount, then n positive coin denominations.
    // Print the number of unordered combinations modulo 1000000007.
    return 0;
}
