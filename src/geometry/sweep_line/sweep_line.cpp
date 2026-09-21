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
    vector<int> x1(n), y1(n), x2(n), y2(n);
    vector<int> xs;
    for (int i = 0; i < n; ++i) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        xs.push_back(x1[i]);
        xs.push_back(x2[i]);
    }
    sort(xs.begin(), xs.end());
    xs.erase(unique(xs.begin(), xs.end()), xs.end());
    int ans = 0;
    int nx = xs.size();
    for (int i = 0; i + 1 < nx; ++i) {
        int left = xs[i];
        int right = xs[i + 1];
        int width = right - left;
        vector<pair<int, int>> segs;
        for (int j = 0; j < n; ++j) {
            if (x1[j] <= left && x2[j] >= right) {
                segs.push_back({y1[j], y2[j]});
            }
        }
        sort(segs.begin(), segs.end());
        int cover = 0;
        int last = -4e18;
        for (auto [lo, hi] : segs) {
            if (hi <= last) {
                continue;
            }
            if (lo < last) {
                lo = last;
            }
            cover += hi - lo;
            last = hi;
        }
        ans += cover * width;
    }
    cout << ans << '\n';
    return 0;
}
