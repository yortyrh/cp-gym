#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 15-puzzle inversion parity ===
// Count inversions among nonzero tiles in row-major order.
// blank_row = index / 4 for the zero.
// Solvable iff (inversions + blank_row) % 2 == 1.

signed main() {
    // === I/O ===
    // Read 16 tiles. Print YES if the 15-puzzle is solvable, else NO.
    return 0;
}
