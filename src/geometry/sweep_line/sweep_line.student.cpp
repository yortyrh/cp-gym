#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sweep line (union of axis-aligned rectangles) ===
// Compress x-coordinates. Between consecutive x-values, collect y-intervals of
// rectangles that fully cover that vertical slab, merge them, multiply coverage by width.
// Do not rasterize a dense grid.

signed main() {
    // === I/O ===
    // Read n and n rectangles x1 y1 x2 y2. Print the union area.
    return 0;
}
