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
    vector<int> block_sum(blocks), add(blocks);
    for (int i = 1; i <= n; ++i) {
        block_sum[(i - 1) / B] += a[i];
    }
    auto block_len = [&](int block) {
        int begin = block * B + 1;
        int end = min(n, begin + B - 1);
        return end - begin + 1;
    };
    auto range_add = [&](int l, int r, int v) {
        int left_block = (l - 1) / B;
        int right_block = (r - 1) / B;
        if (left_block == right_block) {
            for (int i = l; i <= r; ++i) {
                a[i] += v;
            }
            block_sum[left_block] += v * (r - l + 1);
            return;
        }
        int left_end = min(n, (left_block + 1) * B);
        for (int i = l; i <= left_end; ++i) {
            a[i] += v;
        }
        block_sum[left_block] += v * (left_end - l + 1);
        for (int block = left_block + 1; block < right_block; ++block) {
            add[block] += v;
            block_sum[block] += v * block_len(block);
        }
        int right_begin = right_block * B + 1;
        for (int i = right_begin; i <= r; ++i) {
            a[i] += v;
        }
        block_sum[right_block] += v * (r - right_begin + 1);
    };
    auto range_sum = [&](int l, int r) {
        int left_block = (l - 1) / B;
        int right_block = (r - 1) / B;
        int total = 0;
        if (left_block == right_block) {
            for (int i = l; i <= r; ++i) {
                total += a[i] + add[left_block];
            }
            return total;
        }
        int left_end = min(n, (left_block + 1) * B);
        for (int i = l; i <= left_end; ++i) {
            total += a[i] + add[left_block];
        }
        for (int block = left_block + 1; block < right_block; ++block) {
            total += block_sum[block];
        }
        int right_begin = right_block * B + 1;
        for (int i = right_begin; i <= r; ++i) {
            total += a[i] + add[right_block];
        }
        return total;
    };
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l, r, v;
            cin >> l >> r >> v;
            range_add(l, r, v);
        } else {
            int l, r;
            cin >> l >> r;
            cout << range_sum(l, r) << '\n';
        }
    }
    return 0;
}
