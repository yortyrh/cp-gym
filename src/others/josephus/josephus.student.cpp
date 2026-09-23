#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Josephus recurrence f(n) = (f(n-1)+k) mod n ===
// result = 0; for count = 1..n: result = (result + k) % count.
// Do not simulate a linked list.

signed main() {
    // === I/O ===
    // Read q pairs (n, k). Print the 0-based Josephus survivor.
    return 0;
}
