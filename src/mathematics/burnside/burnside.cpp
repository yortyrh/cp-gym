#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
    }
};
static FastIO fastio;

int gcd_abs(int a, int b) {
    while (b != 0) {
        int next = a % b;
        a = b;
        b = next;
    }
    return a;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int colors, beads;
        cin >> colors >> beads;
        int total = 0;
        for (int rotation = 0; rotation < beads; ++rotation) {
            int cycles = gcd_abs(rotation, beads);
            int term = 1;
            for (int i = 0; i < cycles; ++i) {
                term *= colors;
            }
            total += term;
        }
        cout << total / beads << '\n';
    }
    return 0;
}
