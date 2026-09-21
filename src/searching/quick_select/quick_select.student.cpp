#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: quickselect (3-way partition) ===
// Pivot at the middle of the current range. Partition into < pivot, = pivot,
// > pivot. Recurse on the side that still contains the 0-based rank k.
// Average O(n). Do not fully sort. Do not call std::nth_element.

signed main() {
    // === I/O ===
    // Read n, k and the array a[0..n-1].
    // Print the k-th smallest value (0-based rank).
    return 0;
}
