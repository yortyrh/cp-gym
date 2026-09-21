#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: inclusion-exclusion for two sets ===
// count = n/a + n/b - n/lcm(a,b).
// lcm(a,b) = a / gcd(a,b) * b. Watch overflow: divide before multiplying, then n / lcm.

signed main() {
    // === I/O ===
    // Read q triples (n, a, b). Print how many integers in 1..n are divisible by a or b.
    return 0;
}
