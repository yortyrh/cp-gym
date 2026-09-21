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

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n, prime;
        cin >> n >> prime;
        int exponent = 0;
        while (n > 0) {
            n /= prime;
            exponent += n;
        }
        cout << exponent << '\n';
    }
    return 0;
}
