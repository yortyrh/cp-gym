#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: deterministic Miller-Rabin for 64-bit integers ===
// Handle n < 2 as composite. Trial-divide by the small primes listed in the statement.
// Write n-1 = 2^s * d. For each witness a, if a^d % n is 1 or n-1, a passes.
// Otherwise square up to s-1 times looking for n-1. If none, n is composite.
// Use a 64-bit-safe modular multiply (add-and-double or __int128).

signed main() {
    // === I/O ===
    // Read q values of n. Print YES or NO for each.
    return 0;
}
