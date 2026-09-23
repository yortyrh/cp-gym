#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kahn topological sort (lexicographically smallest) ===
// Convert 1-based vertices to 0-based when reading.
// The graph is directed. Compute indegrees, then push every indegree-0 vertex
// into a min-heap. Repeatedly pop the smallest vertex and reduce successor indegrees.
// If you emit fewer than n vertices, a cycle exists: print -1.
// A FIFO queue is not enough: the order must be lexicographically smallest.

signed main() {
    // === I/O ===
    // Read n, m and m directed edges (1-based). Convert to 0-based at I/O.
    // Print n vertices in lex-smallest topological order, or -1 if a cycle exists.
    return 0;
}
