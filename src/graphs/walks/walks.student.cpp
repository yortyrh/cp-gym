#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: walks of length k by matrix exponentiation ===
// (A^k)[i][j] is the number of directed walks of length k from i to j.
// Start from the identity matrix and square the adjacency matrix with binary exponentiation.
// n is small; do not DFS every walk.

signed main() {
    // === I/O ===
    // Read n, k, then an n x n adjacency matrix of non-negative integers.
    // Print A^k as n lines of n integers.
    return 0;
}
