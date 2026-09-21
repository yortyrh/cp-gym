#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Aho–Corasick automaton ===
// Trie on a–z. Missing child = -1. After inserting all patterns, BFS-build
// failure links: missing edges follow the fail, and outputs copy from the fail
// so a suffix-pattern is reported when a longer pattern matches.
// Search the text once. Arrays/nodes are 0-based. Do not run KMP per pattern.

signed main() {
    // === I/O ===
    // Read k patterns, then the text t.
    // Print k lines: occurrence count of each pattern in t (overlaps count).
    return 0;
}
