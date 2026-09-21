#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
//   cout.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: 2-SAT via implication graph SCCs ===
// Variable i (0-based) has true literal 2*i and false literal 2*i+1. Clause (a \/ b) adds
// ~a -> b and ~b -> a. Tarjan SCCs: unsatisfiable iff a variable and its negation share a component.
// Assign true when the true-literal's component id is smaller. n is small.

signed main() {
    // === I/O ===
    // Read n, m, then m clauses. Each clause is two signed integers: +x is x true, -x is x false.
    // Print NO, or YES and n values in {0,1}.
    return 0;
}
