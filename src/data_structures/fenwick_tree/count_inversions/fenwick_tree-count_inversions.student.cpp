#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick frequency tree plus coordinate compression ===
// Compress values, then scan left to right.
// For each a[i], add prefix_sum(rank(a[i]) + 1 .. universe) to the answer
// (already-seen values strictly greater than a[i]), then add(rank(a[i]), 1).
// Do not use O(n^2) pair enumeration. Do not use a balanced BST for this exercise.

signed main() {
    // === I/O ===
    // Read n and the array a[1..n].
    // Print one integer: the number of pairs i < j with a[i] > a[j].
    return 0;
}
