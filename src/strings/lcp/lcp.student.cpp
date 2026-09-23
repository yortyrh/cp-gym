#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Kasai longest common prefix array ===
// Build the suffix array, then rank[sa[i]] = i.
// Walk suffixes in text order. Reuse the previous LCP minus one.
// lcp[0] = 0, lcp[i] = LCP(sa[i-1], sa[i]). Arrays are 0-based.
// Do not recompute every adjacent pair of suffixes from index 0.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print n integers: the Kasai LCP array of s.
    return 0;
}
