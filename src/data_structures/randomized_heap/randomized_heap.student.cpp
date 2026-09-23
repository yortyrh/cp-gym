#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: randomized meldable min-heap ===
// meld(a, b): if either is null return the other; keep the smaller root;
// swap that root's children with probability 1/2; recurse on the right child.
// insert(x) = meld with a single-node heap.
// extract-min = meld the root's two children.
// meld_with(j) moves every node of heap j into heap i.
// Do not rebuild a sorted container on every query.

signed main() {
    // === I/O ===
    // Read n, q. Heaps are labeled 1..n and start empty.
    //   type 1 i x  → insert x into heap i
    //   type 2 i    → print the minimum of heap i
    //   type 3 i    → extract-min of heap i and print it
    //   type 4 i j  → meld heap j into heap i (heap j becomes empty)
    // Write answers to stdout.
    return 0;
}
