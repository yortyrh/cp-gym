#include<bits/stdc++.h>
using namespace std;
#define int long long

struct FastIO {
    FastIO() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    }
};
static FastIO fastio;

int gcd_abs(int a, int b) {
    if (a < 0) {
        a = -a;
    }
    if (b < 0) {
        b = -b;
    }
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
        int a, b;
        cin >> a >> b;
        int g = gcd_abs(a, b);
        int aa = a < 0 ? -a : a;
        int bb = b < 0 ? -b : b;
        int ell = 0;
        if (aa != 0 && bb != 0) {
            ell = aa / g * bb;
        }
        cout << g << ' ' << ell << '\n';
    }
    return 0;
}
