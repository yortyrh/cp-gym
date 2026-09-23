#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: minimum path cover in a DAG via bipartite matching ===
// Split each vertex into left (out) and right (in). Each DAG edge u -> v is a left-u to right-v edge.
// Maximum matching = number of "connections" between vertices on paths.
// Answer = n - matching. Every vertex lies on exactly one path. The input is a DAG.

signed main() {
    // === I/O ===
    // Read n, m and m directed DAG edges. Print the size of a minimum path cover.
    return 0;
}
