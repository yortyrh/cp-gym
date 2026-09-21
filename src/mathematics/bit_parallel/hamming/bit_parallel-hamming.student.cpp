#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: bit-parallel Hamming distance (xor + popcount) ===
// Pack each 0/1 string into 64-bit words (60 bits per word is fine).
// Distance(i, k) = sum over words of popcount(word[i] xor word[k]).
// Print the minimum distance among all pairs. Do not compare bits one by one.

signed main() {
    // === I/O ===
    // Read n, m and n binary strings of length m. Print the minimum Hamming distance.
    return 0;
}
