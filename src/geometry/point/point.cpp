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
        int type;
        cin >> type;
        if (type == 1) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            cout << ax * bx + ay * by << '\n';
        } else if (type == 2) {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            cout << ax * by - ay * bx << '\n';
        } else if (type == 3) {
            int ox, oy, ax, ay, bx, by;
            cin >> ox >> oy >> ax >> ay >> bx >> by;
            int ux = ax - ox;
            int uy = ay - oy;
            int vx = bx - ox;
            int vy = by - oy;
            cout << ux * vy - uy * vx << '\n';
        } else {
            int ax, ay, bx, by;
            cin >> ax >> ay >> bx >> by;
            cout << fixed << setprecision(10) << hypot(ax - bx, ay - by) << '\n';
        }
    }
    return 0;
}
