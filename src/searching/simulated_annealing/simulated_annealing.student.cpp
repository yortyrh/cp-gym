#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: simulated annealing (1D minimization) ===
// Energy of x is (x - t)^2. mt19937 seed 1, 2000 steps.
// Temperature T = 1 - i/steps. Neighbour = current + U(-1,1)*(0.1+T).
// Accept downhill always; uphill with probability exp(-Δ/T).
// Keep the best position. Do not jump directly to t.

signed main() {
    // === I/O ===
    // Read start s and target t.
    // Print the best position found, with exactly 10 digits after the decimal point.
    return 0;
}
