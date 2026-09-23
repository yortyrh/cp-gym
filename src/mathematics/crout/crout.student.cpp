#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: determinant via Crout LU (unit diagonal on U) ===
// U diagonal is 1. For each j:
// L[i][j] = A[i][j] - sum_k L[i][k]*U[k][j] for i >= j.
// If |L[j][j]| < 1e-9, det = 0.
// U[j][i] = (A[j][i] - sum_k L[j][k]*U[k][i]) / L[j][j] for i > j.
// det is the product of L[j][j].

signed main() {
    // === I/O ===
    // Read n and an n by n matrix. Print det from Crout LU with 10 decimals.
    return 0;
}
