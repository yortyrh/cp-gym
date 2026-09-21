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
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }
    double twice = 0;
    for (int i = 0; i < n; ++i) {
        int j = i + 1;
        if (j == n) {
            j = 0;
        }
        twice += (double)x[i] * y[j] - (double)y[i] * x[j];
    }
    cout << twice / 2.0 << '\n';
    return 0;
}
