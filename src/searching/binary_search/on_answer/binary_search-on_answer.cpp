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
    int n, k;
    cin >> n >> k;
    vector<int> lengths(n);
    int longest = 0;
    for (int i = 0; i < n; ++i) {
        cin >> lengths[i];
        longest = max(longest, lengths[i]);
    }
    int lo = 0;
    int hi = longest + 1;
    while (lo + 1 < hi) {
        int mid = lo + (hi - lo) / 2;
        int pieces = 0;
        for (int length : lengths) {
            pieces += length / mid;
            if (pieces >= k) {
                break;
            }
        }
        if (pieces >= k) {
            lo = mid;
        } else {
            hi = mid;
        }
    }
    cout << lo << '\n';
    return 0;
}
