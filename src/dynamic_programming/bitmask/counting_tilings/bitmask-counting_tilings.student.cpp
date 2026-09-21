#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: profile bitmask DP ===
// After swapping so n <= m, mask bits are the n rows of the current column
// that are already filled by a horizontal tile. Fill a column with a recursion
// on the row index: skip a prefilled cell, place a vertical domino, or start
// a horizontal domino (set the same row in the next mask). Do not backtrack
// cell by cell over the full n*m grid.

signed main() {
    // === I/O ===
    // Read n and m. Print the number of domino tilings of the n x m grid.
    return 0;
}
