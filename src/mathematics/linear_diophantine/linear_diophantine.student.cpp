#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: linear Diophantine equation via extended Euclid ===
// Run extended Euclid on (a, b). If g == 0, solvable only when c == 0.
// If c is not divisible by g, print -1.
// Particular solution: (x0 * c/g, y0 * c/g). Steps: (b/g, -a/g).

signed main() {
    // === I/O ===
    // Read q triples (a, b, c). Print -1, or a particular (x, y) and the steps.
    return 0;
}
