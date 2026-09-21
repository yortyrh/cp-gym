#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Stoer-Wagner global minimum cut ===
// Undirected weighted adjacency matrix. Run n-1 maximum-adjacency phases.
// Each phase repeatedly adds the unused vertex with the largest adjacency weight to the set.
// The cut-of-the-phase is the weight of the last added vertex; contract the last two vertices.
// The answer is the minimum cut-of-the-phase. n is small; O(n^3) is intended.

signed main() {
    // === I/O ===
    // Read n, then an n x n symmetric weight matrix (zeros on the diagonal).
    // Print the global minimum cut value.
    return 0;
}
