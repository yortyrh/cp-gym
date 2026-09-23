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

    int range_sum(int l, int r) {
        if (l > r) {
            return 0;
        }
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

signed main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<int> values(a.begin() + 1, a.end());
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());
    auto rank_of = [&](int x) {
        return (lower_bound(values.begin(), values.end(), x) - values.begin()) + 1;
    };
    Fenwick tree(values.size());
    int answer = 0;
    for (int i = 1; i <= n; ++i) {
        int r = rank_of(a[i]);
        answer += tree.range_sum(r + 1, tree.n);
        tree.add(r, 1);
    }
    cout << answer << '\n';
    return 0;
}
