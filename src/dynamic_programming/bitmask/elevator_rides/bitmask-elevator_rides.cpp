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
    int n, limit;
    cin >> n >> limit;
    vector<int> weight(n);
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    int full = 1 << n;
    vector<pair<int, int>> best(full, {n + 1, 0});
    best[0] = {1, 0};
    for (int mask = 1; mask < full; ++mask) {
        for (int person = 0; person < n; ++person) {
            if ((mask & (1 << person)) == 0) {
                continue;
            }
            pair<int, int> option = best[mask ^ (1 << person)];
            if (option.second + weight[person] <= limit) {
                option.second += weight[person];
            } else {
                option.first += 1;
                option.second = weight[person];
            }
            best[mask] = min(best[mask], option);
        }
    }
    cout << best[full - 1].first << '\n';
    return 0;
}
