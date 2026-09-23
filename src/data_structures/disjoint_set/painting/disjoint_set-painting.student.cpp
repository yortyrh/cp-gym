#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: DSU jump-to-next-unpainted (offline, right to left) ===
// Later operations overwrite earlier ones, so apply q..1.
// parent[i] = next unpainted index >= i. Sentinel n+1 is never painted.
// After coloring i, set parent[i] = find(i + 1) and continue from there.
// Do not scan every cell of each [l, r] independently.

signed main() {
    // === I/O ===
    // Read n, q and q operations l r c.
    // Print the final colors of cells 1..n (0 if never painted), space-separated.
    return 0;
}
