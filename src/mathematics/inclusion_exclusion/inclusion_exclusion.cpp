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
        int n, a, b;
        cin >> n >> a >> b;
        int g = gcd_abs(a, b);
        int lcm = a / g * b;
        cout << n / a + n / b - n / lcm << '\n';
    }
    return 0;
}
