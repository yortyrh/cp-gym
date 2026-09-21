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

struct Query {
    int l, r, idx;
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<Query> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }
    int B = 1;
    while (B * B < n) {
        ++B;
    }
    sort(queries.begin(), queries.end(), [&](const Query& x, const Query& y) {
        int bx = x.l / B;
        int by = y.l / B;
        if (bx != by) {
            return bx < by;
        }
        if (bx % 2 == 0) {
            return x.r < y.r;
        }
        return x.r > y.r;
    });
    vector<int> freq(1000001);
    vector<int> answers(q);
    int cl = 1;
    int cr = 0;
    int distinct = 0;
    auto add = [&](int i) {
        int value = a[i];
        ++freq[value];
        if (freq[value] == 1) {
            ++distinct;
        }
    };
    auto remove = [&](int i) {
        int value = a[i];
        --freq[value];
        if (freq[value] == 0) {
            --distinct;
        }
    };
    for (const Query& query : queries) {
        while (cr < query.r) {
            ++cr;
            add(cr);
        }
        while (cl > query.l) {
            --cl;
            add(cl);
        }
        while (cr > query.r) {
            remove(cr);
            --cr;
        }
        while (cl < query.l) {
            remove(cl);
            ++cl;
        }
        answers[query.idx] = distinct;
    }
    for (int i = 0; i < q; ++i) {
        cout << answers[i] << '\n';
    }
    return 0;
}
