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

const int inf = 4e18;

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int B = 1;
    while (B * B < n) {
        ++B;
    }
    int blocks = (n + B - 1) / B;
    vector<int> block_min(blocks, inf), lazy(blocks);
    vector<int> has_lazy(blocks);
    auto rebuild = [&](int block) {
        int begin = block * B + 1;
        int end = min(n, begin + B - 1);
        int best = inf;
        for (int i = begin; i <= end; ++i) {
            best = min(best, a[i]);
        }
        block_min[block] = best;
    };
    auto push = [&](int block) {
        if (!has_lazy[block]) {
            return;
        }
        int begin = block * B + 1;
        int end = min(n, begin + B - 1);
        for (int i = begin; i <= end; ++i) {
            a[i] = lazy[block];
        }
        has_lazy[block] = 0;
    };
    auto apply_full = [&](int block, int v) {
        lazy[block] = v;
        has_lazy[block] = 1;
        block_min[block] = v;
    };
    for (int block = 0; block < blocks; ++block) {
        rebuild(block);
    }
    auto range_assign = [&](int l, int r, int v) {
        int left_block = (l - 1) / B;
        int right_block = (r - 1) / B;
        if (left_block == right_block) {
            push(left_block);
            for (int i = l; i <= r; ++i) {
                a[i] = v;
            }
            rebuild(left_block);
            return;
        }
        push(left_block);
        int left_end = min(n, (left_block + 1) * B);
        for (int i = l; i <= left_end; ++i) {
            a[i] = v;
        }
        rebuild(left_block);
        for (int block = left_block + 1; block < right_block; ++block) {
            apply_full(block, v);
        }
        push(right_block);
        int right_begin = right_block * B + 1;
        for (int i = right_begin; i <= r; ++i) {
            a[i] = v;
        }
        rebuild(right_block);
    };
    auto range_min = [&](int l, int r) {
        int left_block = (l - 1) / B;
        int right_block = (r - 1) / B;
        int result = inf;
        auto partial_min = [&](int block, int from, int to) {
            if (has_lazy[block]) {
                result = min(result, lazy[block]);
                return;
            }
            for (int i = from; i <= to; ++i) {
                result = min(result, a[i]);
            }
        };
        if (left_block == right_block) {
            partial_min(left_block, l, r);
            return result;
        }
        partial_min(left_block, l, min(n, (left_block + 1) * B));
        for (int block = left_block + 1; block < right_block; ++block) {
            result = min(result, block_min[block]);
        }
        partial_min(right_block, right_block * B + 1, r);
        return result;
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            range_assign(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << range_min(l, r) << '\n';
        }
    }
    return 0;
}
