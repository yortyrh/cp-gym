#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Floyd tortoise-and-hare cycle detection ===
// tortoise = hare = s.
// Loop: tortoise = f[tortoise]; hare = f[f[hare]]; until they meet.
// Then mu = s; while mu != tortoise: both take one step.
// Then lambda = 1; walk from f[mu] until back at mu.

signed main() {
    // === I/O ===
    // Read n s and the next-array f. Print cycle entrance mu and length lambda.
    return 0;
}
