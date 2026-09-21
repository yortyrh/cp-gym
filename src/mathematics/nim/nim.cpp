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
    int n;
    cin >> n;
    int xr = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        xr ^= a;
    }
    if (xr) {
        cout << "First\n";
    } else {
        cout << "Second\n";
    }
    return 0;
}
