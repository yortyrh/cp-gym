#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: blocked minima with point rebuild ===
// Split a[1..n] into blocks of length about sqrt(n). Store each block's min.
// Point update a[i] = v, then rebuild only that block in O(sqrt n).
// Range min walks leftover elements on the ends and whole-block answers in the
// middle. Do not rebuild the whole array. Do not use a segment tree.

signed main() {
    // === I/O ===
    // Read n, q and the initial array a[1..n].
    // For each query:
    //   type 1 i v  → set a[i] to v and rebuild its block
    //   type 2 l r  → print min(a[l..r]) followed by a newline
    // Write answers to stdout.
    return 0;
}
