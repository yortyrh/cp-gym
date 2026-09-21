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
    double a, b, c;
    double left, right;
    double intervals;
    cin >> a >> b >> c >> left >> right >> intervals;
    auto function = [&](double x) {
        return (a * x + b) * x + c;
    };
    double step = (right - left) / intervals;
    double total = function(left) + function(right);
    int odd = 1;
    for (double index = 1.0; index < intervals; index += 1.0) {
        double x = left + step * index;
        total += function(x) * (odd ? 4.0 : 2.0);
        odd = 1 - odd;
    }
    double area = total * step / 3.0;
    cout << fixed << setprecision(10) << area << '\n';
    return 0;
}
