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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    int j = n - 1;
    while (i < j) {
        int s = a[i] + a[j];
        if (s == x) {
            if (a[i] == a[j]) {
                int len = j - i + 1;
                ans += len * (len - 1) / 2;
                break;
            }
            int left_val = a[i];
            int right_val = a[j];
            int left_cnt = 0;
            int right_cnt = 0;
            while (i < j && a[i] == left_val) {
                ++left_cnt;
                ++i;
            }
            while (j >= i && a[j] == right_val) {
                ++right_cnt;
                --j;
            }
            ans += left_cnt * right_cnt;
        } else if (s < x) {
            ++i;
        } else {
            --j;
        }
    }
    cout << ans << '\n';
    return 0;
}
