#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: divide-and-conquer DP optimization ===
// Split the array into exactly k contiguous groups. Cost of [l..r] is (sum)^2.
// dp[g][i] = min_{j < i} dp[g-1][j] + cost(j+1, i).
// The optimal j is monotone in i, so compute each layer with D&C:
//   solve(l, r, optl, optr) fills dp for mid then recurses on both halves.
// Do not use a cubic interval DP.

signed main() {
    // === I/O ===
    // Read n, k and n integers. Print the minimum total cost.
    return 0;
}
