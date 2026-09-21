#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: suffix automaton (online construction) ===
// States store length, suffix link, and a map of transitions.
// extend(c) may clone a state. Distinct substrings =
//   sum over v!=0 of (len[v] - len[link[v]]).
// contains(t) walks transitions from state 0. Do not store every substring.

signed main() {
    // === I/O ===
    // Read s, then q query strings.
    // Print the number of distinct nonempty substrings of s, then YES/NO
    // for each query.
    return 0;
}
