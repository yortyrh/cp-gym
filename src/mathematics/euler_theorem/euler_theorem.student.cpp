#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Euler's theorem inverse a^(phi(n)-1) mod n ===
// Compute g = gcd(a, n). If g != 1, print -1.
// Otherwise compute phi(n), then a^(phi(n)-1) mod n by binary exponentiation.
// Do not use extended Euclid for this exercise.

signed main() {
    // === I/O ===
    // Read q pairs (a, n). Print the Euler inverse or -1.
    return 0;
}
