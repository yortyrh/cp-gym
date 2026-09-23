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
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        int result = 0;
        for (int count = 1; count <= n; ++count) {
            result = (result + k) % count;
        }
        cout << result << '\n';
    }
    return 0;
}
