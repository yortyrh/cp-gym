#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kadane's algorithm (maximum subarray) ===
// Scan left to right. Keep the best suffix ending at i (restart if the
// suffix becomes worse than a[i] alone) and the global best sum.
// The subarray is non-empty. Arrays are 0-based. Do not use O(n^2) ranges.

signed main() {
    // === I/O ===
    // Read n and the array a[0..n).
    // Print the maximum sum of a non-empty contiguous subarray.
    return 0;
}
