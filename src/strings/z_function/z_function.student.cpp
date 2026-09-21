#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Z-function (rightmost Z-box) ===
// z[i] = longest prefix of s that starts at i. z[0] = 0.
// Keep the rightmost match window [left, right). If i < right, set
// z[i] = min(right - i, z[i - left]), then extend. Update the window
// when i + z[i] goes past right. Do not compare every suffix from scratch.

signed main() {
    // === I/O ===
    // Read n and the string s of length n.
    // Print n integers: the Z-array of s.
    return 0;
}
