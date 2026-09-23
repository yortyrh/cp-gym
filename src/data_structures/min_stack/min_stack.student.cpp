#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: min-stack (value plus prefix minimum) ===
// Each entry stores (value, min of the stack including that value).
// push(x): min = x if empty, else min(x, previous prefix min).
// pop() and get-min() are O(1). Do not scan the stack on type-3 queries.

signed main() {
    // === I/O ===
    // Read q operations from stdin.
    //   type 1 x  → push x
    //   type 2    → pop
    //   type 3    → print the current minimum
    // Write answers to stdout.
    return 0;
}
