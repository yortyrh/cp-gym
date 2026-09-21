#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: composite Simpson's rule ===
// Integrate ax^2+bx+c on [L, R] with an even number of subintervals m.
// h = (R-L)/m. Sum f(L)+f(R), plus 4f at odd nodes and 2f at even interior
// nodes, then multiply by h/3. Do not use an antiderivative formula.

signed main() {
    // === I/O ===
    // Read a, b, c, then L, R, then even m.
    // Print the Simpson integral with exactly 10 digits after the decimal point.
    return 0;
}
