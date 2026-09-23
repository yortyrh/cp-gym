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

int next_with_same_popcount(int value) {
    int lowest = value & (~value + 1);
    int ripple = value + lowest;
    int ones = (ripple ^ value) >> 2;
    return ripple | (ones / lowest);
}

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << next_with_same_popcount(x) << '\n';
    }
    return 0;
}
