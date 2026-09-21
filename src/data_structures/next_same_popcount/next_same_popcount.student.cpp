#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Gosper's hack (next number with the same number of 1-bits) ===
// lowest = x & (~x + 1)
// ripple = x + lowest
// ones   = (ripple ^ x) >> 2
// next   = ripple | (ones / lowest)
// This is the least integer > x with popcount equal to popcount(x).
// Do not brute-force increment until the popcount matches.

signed main() {
    // === I/O ===
    // Read n, then n positive integers.
    // Print the next same-popcount integer for each, one per line.
    return 0;
}
