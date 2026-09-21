#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 2D segment tree (point assign, rectangle sum) ===
// Implement a 1-based 2D segment tree: an outer tree on rows, each node holding
// an inner tree on columns. Inner nodes of a non-leaf outer node store the sum
// of the corresponding inner nodes of its two children.
// Required operations:
//   set(x, y, v)                    — point-assign cell (x, y)
//   range(x1, y1, x2, y2)           — inclusive subrectangle sum
// Do not rebuild 2D prefix sums on every query. Do not use a 2D Fenwick tree.

signed main() {
    // === I/O ===
    // Read n, m, q and the initial n by m matrix (1-based).
    // Build the 2D segment tree from the matrix.
    // For each query:
    //   type 1 x y v        → set a[x][y] to v
    //   type 2 x1 y1 x2 y2  → print the inclusive subrectangle sum
    // Write answers to stdout.
    return 0;
}
