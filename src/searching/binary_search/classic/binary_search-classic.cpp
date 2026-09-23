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
    int n, q;
    cin >> n >> q;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    while (q--) {
        int x;
        cin >> x;
        int begin = 0;
        int end = n;
        while (begin < end) {
            int middle = begin + (end - begin) / 2;
            if (values[middle] >= x) {
                end = middle;
            } else {
                begin = middle + 1;
            }
        }
        cout << begin << '\n';
    }
    return 0;
}
