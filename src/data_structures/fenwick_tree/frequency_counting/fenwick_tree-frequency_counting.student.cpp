#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Fenwick tree as a frequency table on values 1..n ===
// The Fenwick index is the value itself. No compression.
//   insert x → add(x, 1)
//   erase x  → add(x, -1)
//   count [l, r] → prefix_sum(r) - prefix_sum(l - 1)
// Start from an empty multiset. Do not store the multiset in a map for this exercise.

signed main() {
    // === I/O ===
    // Read n q. n is the value universe (values are in 1..n).
    // Then q queries:
    //   type 1 x   → insert one occurrence of x
    //   type 2 x   → erase one occurrence of x (x is present)
    //   type 3 l r → print how many stored values lie in [l, r]
    // Write answers to stdout.
    return 0;
}
