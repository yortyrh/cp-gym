#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Carmichael theorem a^lambda(n) ≡ 1 (mod n) ===
// If n <= 1, the answer is 0.
// If gcd(a, n) != 1, the answer is 0.
// Otherwise compute a^lambda(n) mod n and test equality with 1.

signed main() {
    // === I/O ===
    // Read q pairs (a, n). Print 1 if Carmichael's congruence holds, else 0.
    return 0;
}
