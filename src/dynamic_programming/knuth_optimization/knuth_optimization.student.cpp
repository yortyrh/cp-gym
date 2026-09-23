#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Knuth optimization (adjacent merge / optimal BST style) ===
// dp[l][r] = min over mid in [l, r) of dp[l][mid] + dp[mid+1][r] + sum(l..r).
// Knuth: opt[l][r-1] <= opt[l][r] <= opt[l+1][r], so only scan that range.
// Fill by increasing interval length. Arrays are 0-based.

signed main() {
    // === I/O ===
    // Read n and n positive integers. Print the minimum merge cost.
    return 0;
}
