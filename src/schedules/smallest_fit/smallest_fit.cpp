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
    int n, m;
    cin >> n >> m;
    vector<int> demands(n), supplies(m);
    for (int i = 0; i < n; ++i) {
        cin >> demands[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> supplies[i];
    }
    sort(demands.begin(), demands.end());
    sort(supplies.begin(), supplies.end());
    int supply_index = 0;
    int total = 0;
    bool ok = true;
    for (int demand : demands) {
        while (supply_index < m && supplies[supply_index] < demand) {
            ++supply_index;
        }
        if (supply_index == m) {
            ok = false;
            break;
        }
        total += supplies[supply_index];
        ++supply_index;
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        cout << total << '\n';
    }
    return 0;
}
