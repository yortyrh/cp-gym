#include<bits/stdc++.h>
using namespace std;
#define int long long

// === FastIO ===
// Enable fast C++ I/O here:
//   ios_base::sync_with_stdio(false);
//   cin.tie(nullptr);
// Prefer a small FastIO struct constructed at startup. Do not use scanf/printf.

// === Technique: min-queue (two min-stacks) ===
// Front and back min-stacks simulate a FIFO queue.
// push(x) goes onto the back stack.
// When front is empty, move every back element onto front (this reverses order).
// Queue min = min of the two stacks' prefix minima (ignore an empty stack).
// Do not scan the queue on type-3 queries. A sliding-window deque is also accepted.

signed main() {
    // === I/O ===
    // Read q operations from stdin.
    //   type 1 x  → push x to the back
    //   type 2    → pop the front
    //   type 3    → print the current minimum
    // Write answers to stdout.
    return 0;
}
