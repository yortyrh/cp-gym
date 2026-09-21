#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: subset-sum DP (boolean 0-1 knapsack) ===
// reachable[s] = true iff a subset of the numbers sums to exactly s.
// reachable[0] = true. For each number, loop the target downward so it is
// used at most once. Arrays are 0-based. Do not enumerate 2^n subsets.

signed main() {
    // === I/O ===
    // Read n, S, then n positive integers.
    // Print YES if some subset sums to S, otherwise NO.
    return 0;
}
