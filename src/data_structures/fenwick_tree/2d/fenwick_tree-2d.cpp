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

struct Fenwick2D {
    int n, m;
    vector<vector<int>> bit;
    Fenwick2D(int n, int m) : n(n), m(m), bit(n + 1, vector<int>(m + 1)) {}

    void add(int x, int y, int delta) {
        for (int i = x; i <= n; i += i & -i) {
            for (int j = y; j <= m; j += j & -j) {
                bit[i][j] += delta;
            }
        }
    }

    int prefix(int x, int y) {
        int result = 0;
        for (int i = x; i > 0; i -= i & -i) {
            for (int j = y; j > 0; j -= j & -j) {
                result += bit[i][j];
            }
        }
        return result;
    }

    int range(int x1, int y1, int x2, int y2) {
        return prefix(x2, y2) - prefix(x1 - 1, y2) - prefix(x2, y1 - 1) + prefix(x1 - 1, y1 - 1);
    }
};

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    Fenwick2D tree(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            tree.add(i, j, a[i][j]);
        }
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            tree.add(x, y, v - a[x][y]);
            a[x][y] = v;
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.range(x1, y1, x2, y2) << '\n';
        }
    }
    return 0;
}
