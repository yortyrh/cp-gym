#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: prefix function (count each prefix as a substring) ===
// Compute pi, then:
//   occ[pi[i]]++ for every i
//   for i = n-1 down to 1: occ[pi[i-1]] += occ[i]
//   occ[i]++ for every i (the prefix itself)
// occ[k] is the number of occurrences of the prefix of length k.
// Arrays are 0-based. Do not run a separate substring search for each k.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print n integers: occurrence counts of prefixes of lengths 1..n.
    return 0;
}
