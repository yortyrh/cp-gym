#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: Johnson's rule for two-machine flow shop ===
// Split jobs into A_i <= B_i and the rest.
// Sort the first group by increasing A_i.
// Sort the second group by increasing B_i, then reverse it.
// Concatenate first group then second group.

signed main() {
    // === I/O ===
    // Read n jobs (A_i, B_i). Print 0-based Johnson order.
    return 0;
}
