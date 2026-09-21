#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Mo's algorithm (offline distinct-count queries) ===
// Read all queries first. Sort by block of l (length about sqrt(n)), then by r
// (odd-even r order is optional but helps).
// Maintain a window [cl, cr] and freq[value] for values in 1..1e6.
// add(i): ++freq[a[i]]; if it becomes 1, ++distinct
// remove(i): --freq[a[i]]; if it becomes 0, --distinct
// Move cl/cr to each query's [l, r] and store distinct at that query's index.
// Print answers in input order. Do not use a Fenwick tree or segment tree.

signed main() {
    // === I/O ===
    // Read n, q and the array a[1..n] (values in 1..1e6).
    // Read q inclusive queries l r.
    // Print one distinct-count per query, in the original order.
    return 0;
}
