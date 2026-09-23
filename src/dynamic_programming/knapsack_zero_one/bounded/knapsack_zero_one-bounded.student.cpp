#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bounded knapsack via binary splitting ===
// Item i may be taken at most k_i times. Split k_i into 0-1 groups whose
// sizes are 1, 2, 4, ..., remainder. Then run classic 0-1 knapsack
// (capacity decreasing) on the split items.
// Arrays are 0-based. Do not loop k_i times on the original item.

signed main() {
    // === I/O ===
    // Read n, W, then n lines of weight, value, and count.
    // Print the maximum total value whose weights sum to at most W.
    return 0;
}
