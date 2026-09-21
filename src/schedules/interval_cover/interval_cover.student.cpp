#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: greedy minimum interval cover ===
// Sort by begin. covered = L, index = 0, used = 0.
// While covered < R: scan intervals with begin <= covered, track max end.
// If max end == covered, impossible. Else covered = max end, ++used.

signed main() {
    // === I/O ===
    // Read L R, then n intervals. Print the minimum cover size or -1.
    return 0;
}
