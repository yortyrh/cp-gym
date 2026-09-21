#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary lifting LCA ===
// Root at 0. up[v][k] is the 2^k-th ancestor. Lift the deeper vertex to the same depth,
// then lift both until their ancestors match. Return the parent of the last mismatch.
// Vertices are 1-based on input/output.

signed main() {
    // === I/O ===
    // Read n, q, then n-1 tree edges (1-based, root 1), then q queries u v.
    // Print the 1-based lowest common ancestor of u and v for each query.
    return 0;
}
