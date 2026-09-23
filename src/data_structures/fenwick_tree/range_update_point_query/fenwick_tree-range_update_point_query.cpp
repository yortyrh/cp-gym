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

struct Fenwick {
    int n;
    vector<int> bit;
    explicit Fenwick(int n) : n(n), bit(n + 1) {}

    void add(int i, int delta) {
        for (; i <= n; i += i & -i) {
            bit[i] += delta;
        }
    }

    int prefix_sum(int i) {
        int result = 0;
        for (; i > 0; i -= i & -i) {
            result += bit[i];
        }
        return result;
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    Fenwick tree(n);
    int prev = 0;
    for (int i = 1; i <= n; ++i) {
        int value;
        cin >> value;
        tree.add(i, value - prev);
        prev = value;
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            tree.add(l, v);
            if (r + 1 <= n) {
                tree.add(r + 1, -v);
            }
        } else {
            int i;
            cin >> i;
            cout << tree.prefix_sum(i) << '\n';
        }
    }
    return 0;
}
