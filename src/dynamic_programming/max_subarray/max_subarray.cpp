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
    int best = values[0];
    int current = values[0];
    for (int i = 1; i < n; ++i) {
        current = max(values[i], current + values[i]);
        best = max(best, current);
    }
    cout << best << '\n';
    return 0;
}
