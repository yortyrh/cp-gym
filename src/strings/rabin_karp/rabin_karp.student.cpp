#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Rabin–Karp (rolling hash plus exact compare) ===
// Hash the text and the pattern with B = 911382323, M = 1e9+7,
// character c mapped to (unsigned char)c + 1.
// Every window whose hash equals the pattern hash must still be compared
// exactly. Record 0-based starts of true matches. Do not use KMP here.

signed main() {
    // === I/O ===
    // Read text t, then pattern p.
    // Print the number of (possibly overlapping) occurrences, then
    // the 0-based starting indices in increasing order.
    return 0;
}
