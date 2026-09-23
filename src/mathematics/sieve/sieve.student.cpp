#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Sieve of Eratosthenes ===
// boolean array prime[0..n], set 0 and 1 false.
// For p = 2..sqrt(n), if prime[p], mark p*p, p*p+p, ... as false.
// Collect remaining true indices from 2 to n.

signed main() {
    // === I/O ===
    // Read n. Print every prime <= n, space-separated.
    return 0;
}
