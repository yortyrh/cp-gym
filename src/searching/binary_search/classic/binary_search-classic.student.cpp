#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binary search (first true index) ===
// Search the monotone predicate a[i] >= x on [0, n).
// If the middle is true, end = middle; otherwise begin = middle + 1.
// The loop returns the first true index, or n. Arrays are 0-based.
// Do not scan from the left on every query. Do not call std::lower_bound.

signed main() {
    // === I/O ===
    // Read n, q and the sorted array a[0..n-1].
    // For each query x, print the smallest i with a[i] >= x, or n.
    return 0;
}
