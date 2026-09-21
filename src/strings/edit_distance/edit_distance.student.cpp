#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: edit distance DP (insert, delete, substitute) ===
// dp[i][j] = distance between a[0..i) and b[0..j). dp[i][0] = i, dp[0][j] = j.
// Transition: delete, insert, or substitute (cost 0 if the characters match).
// Arrays are 0-based. Do not search all edit scripts.

signed main() {
    // === I/O ===
    // Read strings a and b.
    // Print the Levenshtein distance.
    return 0;
}
