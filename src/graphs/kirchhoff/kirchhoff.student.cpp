#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kirchhoff matrix-tree theorem ===
// Undirected graph, 1-based vertices. Laplacian L: degree on the diagonal,
// L[u][v] -= 1 for each undirected edge u-v (ignore self-loops).
// Number of spanning trees = |det| of any (n-1) x (n-1) cofactor, e.g. drop
// row 1 and column 1. Compute the determinant by Gaussian elimination.
// n = 1 answers 1. A disconnected graph answers 0.

signed main() {
    // === I/O ===
    // Read n, m and m undirected edges u v.
    // Print the number of spanning trees.
    return 0;
}
