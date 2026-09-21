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

int euler_phi(int n) {
    int result = n;
    int value = n;
    for (int p = 2; p <= value / p; ++p) {
        if (value % p == 0) {
            while (value % p == 0) {
                value /= p;
            }
            result -= result / p;
        }
    }
    if (value > 1) {
        result -= result / value;
    }
    return result;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        cout << euler_phi(n) << '\n';
    }
    return 0;
}
