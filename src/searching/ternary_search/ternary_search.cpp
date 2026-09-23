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
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    int left = 0;
    int right = n - 1;
    while (right - left > 2) {
        int third = (right - left) / 3;
        int left_third = left + third;
        int right_third = right - third;
        if (values[left_third] > values[right_third]) {
            left = left_third;
        } else {
            right = right_third;
        }
    }
    int best = values[left];
    for (int i = left; i <= right; ++i) {
        best = min(best, values[i]);
    }
    cout << best << '\n';
    return 0;
}
