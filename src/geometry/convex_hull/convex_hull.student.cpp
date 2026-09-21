#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: monotone-chain convex hull ===
// Sort by x then y, unique the points.
// If at most 2 remain, that is the hull.
// Lower chain: left to right, pop while orientation <= 0 (not a left turn).
// Upper chain: right to left, same.
// Drop the duplicated endpoints and concatenate.

signed main() {
    // === I/O ===
    // Read n points. Print the CCW hull size and vertices, no collinear middles.
    return 0;
}
