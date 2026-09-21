#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: closest pair of points (divide and conquer) ===
// Sort by x, recurse on left and right halves, merge by y.
// Check a strip of width sqrt(d) around the midline; only a few following y-neighbors matter.
// Print the minimum squared Euclidean distance. Do not check all pairs when n is large.

signed main() {
    // === I/O ===
    // Read n and n points (x, y). Print the minimum squared distance.
    return 0;
}
