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

const double geometry_epsilon = 1e-9;

signed main() {
    cout << fixed << setprecision(10);
    double x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = hypot(x1 - x2, y1 - y2);
    if (dist + min(r1, r2) <= max(r1, r2) + geometry_epsilon) {
        double radius = min(r1, r2);
        cout << acos(-1.0) * radius * radius << '\n';
        return 0;
    }
    if (dist >= r1 + r2 - geometry_epsilon) {
        cout << 0.0 << '\n';
        return 0;
    }
    double r1sq = r1 * r1;
    double r2sq = r2 * r2;
    double alpha = acos(clamp((dist * dist + r1sq - r2sq) / (2.0 * dist * r1), -1.0, 1.0));
    double beta = acos(clamp((dist * dist + r2sq - r1sq) / (2.0 * dist * r2), -1.0, 1.0));
    double area = r1sq * alpha + r2sq * beta -
                  0.5 * sqrt((-dist + r1 + r2) * (dist + r1 - r2) * (dist - r1 + r2) *
                             (dist + r1 + r2));
    cout << area << '\n';
    return 0;
}
