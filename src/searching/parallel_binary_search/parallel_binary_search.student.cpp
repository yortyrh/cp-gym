#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: parallel binary search + DSU ===
// Edges are added in given order (times 1..m). For each query (u, v), find the
// earliest time they share a component, or -1.
// Binary-search all queries together: group by midpoint, replay prefixes with DSU.
// n is tiny, so a per-query scan also works on the sample.

signed main() {
    // === I/O ===
    // Read n, m, q, then m edges, then q pairs. Print one time (or -1) per query.
    return 0;
}
