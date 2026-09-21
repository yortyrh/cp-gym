#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bit manipulation (popcount, trailing zeros, bit width, lowest set bit) ===
// For each x print four values:
//   popcount(x)           — number of 1-bits
//   countr_zero(x)        — trailing zeros; 64 when x == 0
//   bit_width(x)          — 0 if x == 0, else floor(log2(x)) + 1
//   least_set_bit(x)      — x & (~x + 1); 0 when x == 0
// Use builtins or equivalent O(1) bit ops. Do not scan all 64 bits per query.

signed main() {
    // === I/O ===
    // Read n, then n non-negative integers.
    // Print four integers per value, one line each.
    return 0;
}
