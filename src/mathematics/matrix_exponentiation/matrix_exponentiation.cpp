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

const int mod = 1e9 + 7;

void mat_mul(int a[2][2], int b[2][2]) {
    int c[2][2] = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % mod;
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            a[i][j] = c[i][j];
        }
    }
}

signed main() {
    int a, b, n;
    cin >> a >> b >> n;
    a %= mod;
    b %= mod;
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    int m[2][2] = {{a, b}, {1, 0}};
    int r[2][2] = {{1, 0}, {0, 1}};
    int e = n - 1;
    while (e > 0) {
        if (e & 1) {
            mat_mul(r, m);
        }
        mat_mul(m, m);
        e /= 2;
    }
    cout << r[0][0] % mod << '\n';
    return 0;
}
