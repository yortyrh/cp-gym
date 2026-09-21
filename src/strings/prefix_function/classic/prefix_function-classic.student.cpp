#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Knuth–Morris–Pratt prefix (failure) function ===
// pi[i] = longest proper border of s[0..i]. pi[0] = 0.
// For i >= 1, start from pi[i-1] and fall back along pi until the next
// character matches (or the border becomes 0). Then maybe increment.
// Do not compare every prefix against every suffix.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print n integers: the prefix function of s.
    return 0;
}
