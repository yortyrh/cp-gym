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

int rows;
vector<int> ways, next_ways;

void place(int row, int mask, int next_mask) {
    if (row == rows) {
        next_ways[next_mask] += ways[mask];
        return;
    }
    if ((mask >> row) & 1) {
        place(row + 1, mask, next_mask);
        return;
    }
    place(row + 1, mask, next_mask | (1 << row));
    if (row + 1 < rows && ((mask >> (row + 1)) & 1) == 0) {
        place(row + 2, mask, next_mask);
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    if (n > m) {
        swap(n, m);
    }
    rows = n;
    int states = 1 << n;
    ways.assign(states, 0);
    ways[0] = 1;
    for (int col = 0; col < m; ++col) {
        next_ways.assign(states, 0);
        for (int mask = 0; mask < states; ++mask) {
            if (ways[mask]) {
                place(0, mask, 0);
            }
        }
        ways.swap(next_ways);
    }
    cout << ways[0] << '\n';
    return 0;
}
