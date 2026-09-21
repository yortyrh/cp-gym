#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: disjoint-set union (union by size, path compression) ===
// Maintain 1-based parent and size arrays for elements 1..n.
// Required operations:
//   find(v)     — representative of v, with path compression
//   unite(a, b) — merge components by size; do nothing if already united
//   same(a, b)  — true iff find(a) == find(b)
// Do not DFS/BFS the graph on every type-2 query.

signed main() {
    // === I/O ===
    // Read n, q.
    // For each operation:
    //   type 1 a b  → unite a and b
    //   type 2 a b  → print YES if they share a component, otherwise NO
    // Write answers to stdout.
    return 0;
}
