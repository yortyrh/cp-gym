#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sqrt-tree (block prefix/suffix minima + sparse table on blocks) ===
// Split a[0..n) into blocks of length about sqrt(n) (floor(sqrt(n))+1 is fine).
// Inside each block store prefix minima and suffix minima.
// Store each block's minimum and build a sparse table on those block answers.
// Query [l, r] 1-based inclusive:
//   convert to half-open [l-1, r)
//   same block  → scan the segment
//   else        → min(suffix at left, prefix at right-1,
//                      sparse-table min of whole blocks strictly in between)
// Do not use a segment tree or Fenwick tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the static array a[1..n].
    // Answer each query l r with the inclusive range minimum.
    // Write answers to stdout.
    return 0;
}
