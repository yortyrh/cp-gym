#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: area of intersection of two disks ===
// d = distance between centers.
// If d + min(r,R) <= max(r,R): contained, answer pi * min^2.
// If d >= r+R: disjoint, answer 0.
// Else alpha = acos(clamp((d^2 + r^2 - R^2) / (2 d r))), similarly beta for the other.
// answer = r^2 alpha + R^2 beta - 0.5 * sqrt((-d+r+R)(d+r-R)(d-r+R)(d+r+R)).

signed main() {
    // === I/O ===
    // Read two disks (x, y, r). Print their intersection area with 10 decimals.
    return 0;
}
