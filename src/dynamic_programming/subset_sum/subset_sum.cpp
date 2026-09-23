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
    int n, target;
    cin >> n >> target;
    vector<char> reachable(target + 1, 0);
    reachable[0] = 1;
    for (int i = 0; i < n; ++i) {
        int weight;
        cin >> weight;
        if (weight > target) {
            continue;
        }
        for (int current = target; current >= weight; --current) {
            if (reachable[current - weight]) {
                reachable[current] = 1;
            }
        }
    }
    cout << (reachable[target] ? "YES" : "NO") << '\n';
    return 0;
}
