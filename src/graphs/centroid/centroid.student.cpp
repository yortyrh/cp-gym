#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: centroid decomposition ===
// A centroid's removal leaves components of size <= n/2. Compute subtree sizes, walk to the centroid,
// mark it removed, recurse. parent[centroid] is the centroid of the previous layer (0 for the root).
// n is small. Print 1-based parents; the top centroid's parent is 0.

signed main() {
    // === I/O ===
    // Read n, then n-1 tree edges (1-based).
    // Print n integers: centroid-tree parent of each vertex, or 0 for the root centroid.
    return 0;
}
