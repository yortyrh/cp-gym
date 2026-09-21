#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: nearest smaller to the left (monotonic stack) ===
// Scan left to right. Keep a stack of increasing values with their 1-based indices.
// Pop while the top is >= a[i]. The new top is the nearest strictly smaller left neighbor.
// Print 0 if none exists. Do not scan left from each index.

signed main() {
    // === I/O ===
    // Read n and n integers. Print n 1-based indices (or 0), space-separated.
    return 0;
}
