#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: submask enumeration (sub = (sub - 1) & mask) ===
// Start at sub = mask. Print sub, then sub = (sub - 1) & mask, until sub wraps
// back to mask. This visits every subset of the set bits, including 0 and mask.
// Print the values in that order, space-separated, one query per line.
// Do not scan 0..mask and test (x & mask) == x.

signed main() {
    // === I/O ===
    // Read q, then q masks.
    // For each mask print all submasks in classic-loop order.
    return 0;
}
