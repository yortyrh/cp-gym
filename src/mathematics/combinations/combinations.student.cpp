#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: lexicographic k-subset generation ===
// Initialize combination[i] = i.
// Loop: visit, then find the rightmost index with combination[index] < n-k+index, increment, and set combination[j] = combination[j-1]+1 for the suffix.
// Stop when nothing can increase.

signed main() {
    // === I/O ===
    // Read n k. Print every k-subset of 0..n-1 in lexicographic order.
    return 0;
}
