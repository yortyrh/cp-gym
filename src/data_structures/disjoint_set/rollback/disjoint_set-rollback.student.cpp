#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: DSU with rollback (union by size, no path compression) ===
// find(v) walks to the root without compressing.
// unite(a, b) merges by size and pushes (attached child, new root) on a stack
// only when the two vertices were in different components.
// rollback() pops one merge and restores parent and size. Empty stack: no-op.
// Do not use path compression. Do not copy the whole structure to undo.

signed main() {
    // === I/O ===
    // Read n, q.
    // For each operation:
    //   type 1 a b  → unite a and b
    //   type 2 a b  → print YES if they share a component, otherwise NO
    //   type 3      → undo the last successful merge
    // Write answers to stdout.
    return 0;
}
