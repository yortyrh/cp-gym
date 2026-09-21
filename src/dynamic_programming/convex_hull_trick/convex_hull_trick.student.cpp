#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: convex hull trick / Li Chao DP ===
// dp[0] = 0. dp[i] = min over j < i of dp[j] + b[j] * a[i].
// Each j is a line y = b[j] * x + dp[j] queried at x = a[i].
// a is strictly increasing and b is strictly decreasing, so the lower hull is monotone.
// n is small enough for O(n^2); a hull or Li Chao tree is the intended structure.

signed main() {
    // === I/O ===
    // Read n, then n values a[1..n], then n values b[0..n-1]. Print dp[n].
    return 0;
}
