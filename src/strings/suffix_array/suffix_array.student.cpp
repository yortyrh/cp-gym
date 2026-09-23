#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: suffix array by doubling ===
// suffixes[i] = starting index of the i-th smallest suffix.
// Rank by pairs (rank[i], rank[i+len] or -1), double len, reassign ranks
// until they are unique. Arrays are 0-based.
// Do not compare two suffixes character by character for the full sort.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print n 0-based starting indices of suffixes in lexicographic order.
    return 0;
}
