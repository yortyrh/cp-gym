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
    int n, c;
    cin >> n >> c;
    vector<int> freq(c + 1);
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        ++freq[value];
    }
    bool first = true;
    for (int value = 0; value <= c; ++value) {
        for (int k = 0; k < freq[value]; ++k) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << value;
        }
    }
    cout << '\n';
    return 0;
}
