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
    int n, m, e;
    cin >> n >> m >> e;
    vector<vector<int>> left_to_right(n);
    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        left_to_right[u].push_back(v);
    }
    vector<int> match_right(m, -1);
    vector<int> visited(m, 0);
    int timer = 1;
    auto try_kuhn = [&](auto&& self, int left) -> bool {
        for (int right : left_to_right[left]) {
            if (visited[right] == timer) {
                continue;
            }
            visited[right] = timer;
            if (match_right[right] == -1 || self(self, match_right[right])) {
                match_right[right] = left;
                return true;
            }
        }
        return false;
    };
    for (int left = 0; left < n; ++left) {
        ++timer;
        try_kuhn(try_kuhn, left);
    }
    int size = 0;
    for (int left : match_right) {
        if (left != -1) {
            ++size;
        }
    }
    cout << size << '\n';
    return 0;
}
