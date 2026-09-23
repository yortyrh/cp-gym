#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary lifting on a functional graph ===
// Each node has exactly one successor. Precompute up[b][i] = the 2^b-th successor of i.
// For a query (x, k), jump using the bits of k. Do not walk k steps one by one.

signed main() {
    // === I/O ===
    // Read n, q, then n successors (1-based), then q lines x k.
    // Print the k-th successor of x for each query.
    return 0;
}
