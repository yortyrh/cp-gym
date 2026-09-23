#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Prüfer code of a labeled tree ===
// Tree on n vertices labeled 1..n. Repeat n-2 times: find the remaining leaf
// with the smallest id, append its unique remaining neighbour, delete the leaf.
// O(n^2) by scanning for the smallest leaf each step is enough here.
// For n = 2 the code is empty (print a newline only).

signed main() {
    // === I/O ===
    // Read n and n-1 undirected tree edges.
    // Print n-2 integers: the Prüfer code (1-based labels).
    return 0;
}
