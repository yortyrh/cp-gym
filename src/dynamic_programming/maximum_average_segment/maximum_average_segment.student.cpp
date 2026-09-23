#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary search the average plus prefix check ===
// Binary-search the candidate average t. A segment of length at least k
// has average >= t iff some segment of (a_i - t) has nonnegative sum and
// length >= k. Check that with prefix sums in O(n). Arrays are 0-based.
// Do not enumerate every segment.

signed main() {
    // === I/O ===
    // Read n, k, then n integers.
    // Print the maximum average of a contiguous segment of length at least k,
    // with exactly 10 digits after the decimal point.
    return 0;
}
