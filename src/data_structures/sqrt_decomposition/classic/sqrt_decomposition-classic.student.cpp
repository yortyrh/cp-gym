#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sqrt decomposition (point add, range sum) ===
// Split a[1..n] into blocks of length about sqrt(n). Store each block sum.
// Point add: a[i] += v and the corresponding block sum += v, both O(1).
// Range sum: add leftover elements on the two ends and whole-block sums in
// the middle. Do not rebuild prefix sums on every query. Do not use a Fenwick
// tree or segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // For each query:
    //   type 1 i v  → add v to a[i]
    //   type 2 l r  → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
