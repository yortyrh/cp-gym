#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Knuth–Morris–Pratt automaton ===
// Compute pi of the pattern only. Scan the text with a match length.
// On mismatch, jump to pi[matched-1]. When matched == |p|, record
// i+1-|p| and set matched = pi[matched-1] so overlaps are found.
// Do not re-check every alignment from scratch.

signed main() {
    // === I/O ===
    // Read text t, then pattern p.
    // Print the number of (possibly overlapping) occurrences, then
    // the 0-based starting indices in increasing order.
    return 0;
}
