#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary search the answer ===
// Search the monotone predicate "we can cut k candles of length L".
// Keep lo = feasible, hi = infeasible. Mid = lo + (hi-lo)/2.
// Count pieces with length / mid (integer division). Answer 0 if nothing works.
// Do not try every L from the longest stick downward.

signed main() {
    // === I/O ===
    // Read n, k and n stick lengths.
    // Print the maximum equal candle length, or 0.
    return 0;
}
