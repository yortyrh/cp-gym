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

struct SqrtTree {
    int n, B, blocks, levels;
    vector<int> a, prefix, suffix;
    vector<vector<int>> between;

    explicit SqrtTree(const vector<int>& values) : a(values) {
        n = a.size();
        if (n == 0) {
            B = 1;
            blocks = 0;
            levels = 0;
            return;
        }
        B = 0;
        while (B * B <= n) {
            ++B;
        }
        blocks = (n + B - 1) / B;
        prefix.assign(n, 0);
        suffix.assign(n, 0);
        for (int block = 0; block < blocks; ++block) {
            int begin = block * B;
            int end = min(n, begin + B);
            prefix[begin] = a[begin];
            for (int i = begin + 1; i < end; ++i) {
                prefix[i] = min(prefix[i - 1], a[i]);
            }
            suffix[end - 1] = a[end - 1];
            for (int i = end - 1; i > begin; --i) {
                suffix[i - 1] = min(a[i - 1], suffix[i]);
            }
        }
        vector<int> block_best(blocks);
        for (int block = 0; block < blocks; ++block) {
            block_best[block] = suffix[block * B];
        }
        levels = 64 - __builtin_clzll(blocks);
        between.assign(levels, block_best);
        for (int level = 1; level < levels; ++level) {
            int length = 1ll << level;
            between[level].resize(blocks);
            for (int block = 0; block + length <= blocks; ++block) {
                between[level][block] =
                    min(between[level - 1][block], between[level - 1][block + length / 2]);
            }
        }
    }

    int query(int begin, int end) const {
        int left_block = begin / B;
        int right_block = (end - 1) / B;
        if (left_block == right_block) {
            int result = a[begin];
            for (int i = begin + 1; i < end; ++i) {
                result = min(result, a[i]);
            }
            return result;
        }
        int result = min(suffix[begin], prefix[end - 1]);
        if (left_block + 1 < right_block) {
            int from = left_block + 1;
            int to = right_block;
            int level = 63 - __builtin_clzll(to - from);
            int length = 1ll << level;
            result = min(result, min(between[level][from], between[level][to - length]));
        }
        return result;
    }
};

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    SqrtTree tree(a);
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << tree.query(l - 1, r) << '\n';
    }
    return 0;
}
