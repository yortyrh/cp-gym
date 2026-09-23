#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: trie (prefix tree over lowercase letters) ===
// Each edge is one letter a-z. Missing child = -1.
// On insert, walk/create nodes and increment prefix_count on every node after
// the first letter (number of words that pass through that node).
// count_prefix(p) walks p and returns that node's prefix_count, or 0 if missing.
// Duplicate words each increment the counters. Do not scan the word list per query.

signed main() {
    // === I/O ===
    // Read n, q, then n words, then q prefixes.
    // For each prefix, print how many inserted words have that prefix.
    return 0;
}
