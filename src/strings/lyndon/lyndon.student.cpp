#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Duval Lyndon factorization ===
// Three pointers (begin, i, j). While s[i] <= s[j], advance; if s[i] < s[j]
// reset i to begin, else increment i. The period is j-i. Emit factors of
// that length until begin passes i. Arrays are 0-based. Do not try every split.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print the Lyndon factors separated by spaces.
    return 0;
}
