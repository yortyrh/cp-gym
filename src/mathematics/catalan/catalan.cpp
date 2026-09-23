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

int binomial(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k > n - k) {
        k = n - k;
    }
    int result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result / i * (n - k + i) + result % i * (n - k + i) / i;
    }
    return result;
}

signed main() {
    int q;
    cin >> q;
    while (q--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << 1 << '\n';
        } else {
            cout << binomial(2 * n, n) / (n + 1) << '\n';
        }
    }
    return 0;
}
