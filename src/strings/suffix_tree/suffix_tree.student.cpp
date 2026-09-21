#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: compressed suffix trie (suffix tree) ===
// Insert every suffix of s. Edge labels are strings; split an edge when a
// new suffix shares only a prefix of it. contains(t) walks labels and
// children. Root is node 0. Do not scan s for every pattern.

signed main() {
    // === I/O ===
    // Read s, then q patterns.
    // Print YES if the pattern occurs in s, otherwise NO.
    return 0;
}
