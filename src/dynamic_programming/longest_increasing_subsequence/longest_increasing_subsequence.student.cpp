#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: longest strictly increasing subsequence (patience sorting) ===
// tails[len] = index of the smallest tail of an increasing subsequence of
// length len+1. Binary search with lower_bound gives O(n log n).
// Keep a previous[] array and reconstruct one actual subsequence, not only
// the length. Arrays are 0-based. The subsequence must be strictly increasing.
// Do not use O(n^2) DP.

signed main() {
    // === I/O ===
    // Read n and the array a[0..n).
    // Print k, the LIS length, then a line with k values of one LIS.
    return 0;
}
