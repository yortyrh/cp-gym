#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: binomial coefficient product formula ===
// If k < 0 or k > n, answer 0. Replace k by min(k, n-k).
// For i = 1..k: result = result / i * (n-k+i) + result % i * (n-k+i) / i
// (the form that stays exact without a wide product).

signed main() {
    // === I/O ===
    // Read q pairs (n, k). Print C(n, k).
    return 0;
}
