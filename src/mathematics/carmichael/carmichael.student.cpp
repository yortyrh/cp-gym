#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Carmichael lambda from prime powers ===
// Factor n. For p=2: k=1 -> 1, k=2 -> 2, k>=3 -> 2^(k-2).
// For odd p^k: (p-1) * p^(k-1).
// Fold parts together with lcm.

signed main() {
    // === I/O ===
    // Read q values of n. Print lambda(n) for each.
    return 0;
}
