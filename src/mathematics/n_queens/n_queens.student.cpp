#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: N-queens backtracking ===
// columns[row] = chosen column, or -1.
// A cell (row, col) is attacked if some previous queen shares col, col-row, or col+row.
// Search rows 0..n-1, trying columns in increasing order.
// n = 1 has one solution: 0.

signed main() {
    // === I/O ===
    // Read n. Print the number of solutions, then each solution as n column indices.
    return 0;
}
