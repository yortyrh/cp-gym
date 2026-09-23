#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: sqrt decomposition with lazy block adds ===
// Split a[1..n] into blocks of length about sqrt(n).
// Store block_sum[b] and add[b] (lazy increment for every element of block b).
// Range add [l, r] += v:
//   whole blocks → add[b] += v and block_sum[b] += v * length(b)
//   partial blocks → a[i] += v and block_sum[b] += v * (number of touched cells)
// Range sum: whole blocks contribute block_sum[b]; leftover cells contribute
// a[i] + add[b]. Do not use a Fenwick tree or segment tree for this exercise.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // For each query:
    //   type 1 l r v  → add v to every a[i] in [l, r]
    //   type 2 l r    → print range_sum(l, r) followed by a newline
    // Write answers to stdout.
    return 0;
}
