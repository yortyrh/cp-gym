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
    int a, b, c, d, order;
    cin >> a >> b >> c >> d >> order;
    cout << a + c << ' ' << b + d << '\n';
    int k = (order + b) / d;
    cout << k * c - a << ' ' << k * d - b << '\n';
    return 0;
}
