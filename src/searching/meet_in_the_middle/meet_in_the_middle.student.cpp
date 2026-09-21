#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: meet in the middle subset sum ===
// Split the n items into two halves (n <= 40). Enumerate all 2^{n/2} subset sums of each half.
// Sort one half. For every sum L in the other half, count how many R satisfy L + R = x.
// Include the empty subset. Do not enumerate 2^n subsets of the whole array.

signed main() {
    // === I/O ===
    // Read n, x and n integers. Print the number of subsets with sum x.
    return 0;
}
