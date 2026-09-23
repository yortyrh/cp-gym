#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: one-machine Smith's rule (duration/weight order) ===
// Sort jobs by duration * other.weight < other.duration * weight.
// Print original indices in that order. Compare cross-multiplied to avoid floats.

signed main() {
    // === I/O ===
    // Read n jobs (duration, weight). Print 0-based order by Smith's rule.
    return 0;
}
