#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Stern-Brocot tree L/R path ===
// left = (0,1), right = (1,0). Loop:
// mediant = (left_n + right_n, left_d + right_d).
// If equal to (a, b), stop.
// If a * mid_d < b * mid_n, go L and set right = midiant, else go R and set left = mediant.

signed main() {
    // === I/O ===
    // Read a b. Print the Stern-Brocot path (empty for 1/1).
    return 0;
}
