#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: linear recurrence via matrix exponentiation ===
// u[0] = 0, u[1] = 1, u[i] = a * u[i-1] + b * u[i-2] (mod 1e9+7).
// Raise the companion matrix [[a, b], [1, 0]] to the (n-1)-th power.
// Do not iterate n steps when n is up to 1e18.

signed main() {
    // === I/O ===
    // Read a, b, n. Print u[n] modulo 1000000007.
    return 0;
}
