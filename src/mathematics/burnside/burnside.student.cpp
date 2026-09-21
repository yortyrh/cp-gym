#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Burnside lemma on the cyclic group ===
// total = 0; for r in 0..b-1: total += c ^ gcd(r, b); answer = total / b.
// gcd(0, b) = b. Compute the small power by a loop.

signed main() {
    // === I/O ===
    // Read q pairs (colors, beads). Print the Burnside necklace count.
    return 0;
}
