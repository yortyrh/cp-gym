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
    vector<int> tails;
    vector<int> previous(n, -1);
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(tails.begin(), tails.end(), values[i],
                              [&](int tail_index, int value) { return values[tail_index] < value; });
        int length = it - tails.begin();
        if (length > 0) {
            previous[i] = tails[length - 1];
        }
        if (it == tails.end()) {
            tails.push_back(i);
        } else {
            *it = i;
        }
    }
    vector<int> lis;
    for (int i = tails.back(); i != -1; i = previous[i]) {
        lis.push_back(values[i]);
    }
    reverse(lis.begin(), lis.end());
    int k = lis.size();
    cout << k << '\n';
    for (int i = 0; i < k; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << lis[i];
    }
    cout << '\n';
    return 0;
}
