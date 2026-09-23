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

signed main() {
    cout << fixed << setprecision(10);
    double ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    double ux = bx - ax;
    double uy = by - ay;
    double vx = cx - ax;
    double vy = cy - ay;
    double area = fabs(ux * vy - uy * vx) / 2.0;
    double ab = hypot(bx - ax, by - ay);
    double bc = hypot(cx - bx, cy - by);
    double ca = hypot(ax - cx, ay - cy);
    double perimeter = ab + bc + ca;
    double radius = ab * bc * ca / (4.0 * area);
    cout << area << ' ' << perimeter << ' ' << radius << '\n';
    return 0;
}
