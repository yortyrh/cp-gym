#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 2D Fenwick tree (point update, rectangle query) ===
// Implement a 1-based 2D Fenwick tree.
// Index 0 is unused in both dimensions.
// Required operations:
//   add(x, y, delta)              — point update at cell (x, y)
//   prefix(x, y)                  — sum of the rectangle (1,1)..(x,y)
//   range(x1, y1, x2, y2)         — inclusive subrectangle via inclusion-exclusion
// Do not recompute 2D prefix sums on every query. Do not use a 1D Fenwick per row for this exercise.

signed main() {
    // === I/O ===
    // Read n, m, q and the initial n by m matrix (1-based).
    // Build the 2D Fenwick tree from the matrix.
    // For each query:
    //   type 1 x y v        → set a[x][y] to v
    //   type 2 x1 y1 x2 y2  → print the inclusive subrectangle sum
    // Write answers to stdout.
    return 0;
}
