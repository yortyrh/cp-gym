#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary exponentiation with overflow-safe modular multiply ===
// mod_mul: add-and-double, never use a raw a * b when m is large.
// mod_pow: result = 1, square the base, multiply when (e & 1).
// If b is negative, reduce into [0, m) first.

signed main() {
    // === I/O ===
    // Read q triples (b, e, m). Print b^e modulo m.
    return 0;
}
