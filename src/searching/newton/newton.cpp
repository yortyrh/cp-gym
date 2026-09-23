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
    double target;
    cin >> target;
    double current = 1.0;
    for (int iteration = 0; iteration < 40; ++iteration) {
        double slope = 2.0 * current;
        double next = current - (current * current - target) / slope;
        if (abs(next - current) < 1e-10) {
            current = next;
            break;
        }
        current = next;
    }
    cout << fixed << setprecision(10) << current << '\n';
    return 0;
}
