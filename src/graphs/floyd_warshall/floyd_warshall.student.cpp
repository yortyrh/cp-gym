#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Floyd-Warshall all-pairs shortest paths ===
// n x n distance matrix, 0 on the diagonal, inf where there is no edge. Triple loop:
//   d[i][j] = min(d[i][j], d[i][k] + d[k][j])
// Skip a pair when either hop is inf. Print -1 for unreachable pairs. Do not run n Dijkstras.

signed main() {
    // === I/O ===
    // Read n, m, then m directed edges u v w (1-based vertices).
    // Print an n x n matrix of shortest distances, using -1 if no path exists.
    return 0;
}
