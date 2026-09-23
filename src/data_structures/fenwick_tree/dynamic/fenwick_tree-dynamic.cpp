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

    int range_sum(int l, int r) { return prefix_sum(r) - prefix_sum(l - 1); }
};

struct Query {
    int type, x, y;
};

signed main() {
    int q;
    cin >> q;
    vector<Query> queries(q);
    vector<int> coords;
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].type;
        if (queries[i].type == 3) {
            cin >> queries[i].x >> queries[i].y;
            coords.push_back(queries[i].x);
            coords.push_back(queries[i].y);
        } else {
            cin >> queries[i].x;
            coords.push_back(queries[i].x);
        }
    }
    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());
    auto rank_of = [&](int value) {
        return (int)(lower_bound(coords.begin(), coords.end(), value) - coords.begin()) + 1;
    };
    Fenwick tree((int)(coords.size()));
    for (const auto& query : queries) {
        if (query.type == 1) {
            tree.add(rank_of(query.x), 1);
        } else if (query.type == 2) {
            tree.add(rank_of(query.x), -1);
        } else {
            cout << tree.range_sum(rank_of(query.x), rank_of(query.y)) << '\n';
        }
    }
    return 0;
}
