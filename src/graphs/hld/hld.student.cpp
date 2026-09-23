#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: heavy-light decomposition path sums ===
// Root the tree at 0. Heavy child = largest subtree. Map each chain to a contiguous position array.
// A path splits into O(log n) chain segments; sum the stored values on those segments.
// Type 1 writes values[position[v]]. n is small, so scanning a chain is allowed.

signed main() {
    // === I/O ===
    // Read n, q, n vertex values, n-1 edges (1-based), then q queries:
    //   1 v x  — set vertex v's value to x
    //   2 u v  — print the sum of values on the path from u to v
    return 0;
}
