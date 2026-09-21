#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: grid path DP with obstacles ===
// dp[i][j] = ways to reach cell (i, j) moving only right or down.
// Blocked cells (#) stay 0. Free cells add the cell above and the cell to the left.
// Start cell is 1 if it is free. Answer modulo 1e9+7. Arrays are 0-based.

signed main() {
    // === I/O ===
    // Read n, m and n strings of length m. Print the number of paths modulo 1000000007.
    return 0;
}
