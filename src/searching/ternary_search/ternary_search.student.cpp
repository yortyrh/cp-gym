#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: ternary search on a unimodal array ===
// The array decreases to a unique minimum, then increases.
// While the window has more than 3 elements, compare the two interior thirds.
// If a[m1] > a[m2], discard the left third; otherwise discard the right third.
// Then scan the remaining window. Arrays are 0-based. Do not scan all n elements.

signed main() {
    // === I/O ===
    // Read n and the unimodal array.
    // Print the minimum value.
    return 0;
}
