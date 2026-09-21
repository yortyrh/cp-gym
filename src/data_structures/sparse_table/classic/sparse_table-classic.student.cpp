#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sparse table (idempotent RMQ, overlapping intervals) ===
// st[k][i] = min of 2^k elements starting at 1-based index i.
// Precompute floor(log2) so a query [l, r] uses k = lg[r-l+1] and
// min(st[k][l], st[k][r - 2^k + 1]). Overlap is valid because min is idempotent.
// Build O(n log n), query O(1). No updates. Do not scan the range. Do not use
// Fenwick or a segment tree.

signed main() {
    // === I/O ===
    // Read n, q and the array a[1..n].
    // For each query l r, print min(a[l], ..., a[r]) followed by a newline.
    return 0;
}
