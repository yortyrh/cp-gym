#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Euclidean algorithm (GCD and LCM) ===
// Euclid: while b != 0, (a, b) = (b, a % b). Take absolute values first.
// lcm(a, b) = 0 if a == 0 or b == 0, else |a| / gcd * |b|.
// Do not multiply |a| * |b| before dividing; that overflows.

signed main() {
    // === I/O ===
    // Read q, then q pairs (a, b). Print gcd and lcm per pair.
    return 0;
}
