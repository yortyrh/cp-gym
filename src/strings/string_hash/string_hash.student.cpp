#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: polynomial rolling hash ===
// H[i] = s[0]*B^{i-1} + ... + s[i-1] (mod M), with B = 911382323,
// M = 1e9+7, and character c mapped to (unsigned char)c + 1.
// Substring [l, r) is H[r] - H[l]*B^{r-l} (mod M). Build O(n), query O(1).
// Different lengths are never equal. Do not scan the two segments on each query.

signed main() {
    // === I/O ===
    // Read n, q and the string s.
    // Each query is 1-based inclusive l1 r1 l2 r2.
    // Print YES if the two substrings are equal, otherwise NO.
    return 0;
}
