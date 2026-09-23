#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: DSU on tree (sack) ===
// Root the tree at 1. For each node, count distinct colors in its subtree.
// dfs sizes, pick a heavy child. Recurse light children and discard, recurse
// the heavy child and keep, then add light subtrees into the kept map.
// Do not rebuild a frequency map from scratch at every node.

signed main() {
    // === I/O ===
    // Read n, n colors, then n-1 edges. Print n subtree distinct-color counts
    // for nodes 1..n, space-separated.
    return 0;
}
