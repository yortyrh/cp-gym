#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: two pointers on a sorted array ===
// Sort a, then move i from the left and j from the right.
// If a[i] + a[j] equals x, count the pair (handle equal values), then shrink.
// If the sum is too small, ++i. If too large, --j.
// Count unordered pairs of distinct indices. Do not scan all pairs.

signed main() {
    // === I/O ===
    // Read n, x and n integers. Print the number of pairs with sum x.
    return 0;
}
