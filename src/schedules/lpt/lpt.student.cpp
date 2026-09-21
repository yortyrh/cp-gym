#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: longest-processing-time multiprocessor scheduling ===
// Sort durations descending. Keep m machine loads, initially 0.
// For each job, add it to the machine with minimum load.
// Answer is the maximum load. With n <= 1e5, scan m loads naively only if m is small;
// use a min-heap of loads, or scan if you keep m modest. A min-heap of pairs (load, id) is O(n log m).

signed main() {
    // === I/O ===
    // Read n m and n durations. Print the LPT makespan.
    return 0;
}
