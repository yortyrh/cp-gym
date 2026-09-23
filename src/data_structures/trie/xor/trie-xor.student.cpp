#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary trie (maximum XOR of two numbers) ===
// Each node has children 0 and 1 (missing = -1). Insert bits from 30 down to 0.
// max_xor(x) walks preferring the opposite bit; each preferred bit adds that
// power of two to the answer. Insert all numbers, then take max max_xor(a[i]).
// XOR of a number with itself is 0 and does not affect the maximum.
// Do not check all O(n^2) pairs.

signed main() {
    // === I/O ===
    // Read n and the array a[1..n] (0-based storage is fine).
    // Print the maximum a[i] XOR a[j] over i < j.
    return 0;
}
