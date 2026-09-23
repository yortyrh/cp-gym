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
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int pop = __builtin_popcountll(x);
        int tz = x == 0 ? 64 : __builtin_ctzll(x);
        int width = x == 0 ? 0 : 64 - __builtin_clzll(x);
        int lowest = x & (~x + 1);
        cout << pop << ' ' << tz << ' ' << width << ' ' << lowest << '\n';
    }
    return 0;
}
