#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: SOS DP (sum over subsets) ===
// Start with dp[mask] = a[mask]. For bit i from 0 to n-1, for every mask
// with bit i set: dp[mask] += dp[mask ^ (1 << i)]. Do not iterate all pairs
// of masks.

signed main() {
    // === I/O ===
    // Read n and 2^n integers. Print F(mask) for mask = 0 .. 2^n-1,
    // space-separated, followed by a newline.
    return 0;
}
