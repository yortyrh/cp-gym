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

struct SegTree2D {
    int n, m;
    vector<vector<int>> a;
    vector<vector<int>> tree;

    SegTree2D(int n, int m) : n(n), m(m), a(n + 1, vector<int>(m + 1)), tree(4 * n + 4, vector<int>(4 * m + 4)) {}

    void build_y(int vx, int lx, int rx, int vy, int ly, int ry) {
        if (ly == ry) {
            if (lx == rx) {
                tree[vx][vy] = a[lx][ly];
            } else {
                tree[vx][vy] = tree[vx * 2][vy] + tree[vx * 2 + 1][vy];
            }
            return;
        }
        int my = (ly + ry) / 2;
        build_y(vx, lx, rx, vy * 2, ly, my);
        build_y(vx, lx, rx, vy * 2 + 1, my + 1, ry);
        tree[vx][vy] = tree[vx][vy * 2] + tree[vx][vy * 2 + 1];
    }

    void build_x(int vx, int lx, int rx) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            build_x(vx * 2, lx, mx);
            build_x(vx * 2 + 1, mx + 1, rx);
        }
        build_y(vx, lx, rx, 1, 1, m);
    }

    void set_y(int vx, int lx, int rx, int vy, int ly, int ry, int y, int value) {
        if (ly == ry) {
            if (lx == rx) {
                tree[vx][vy] = value;
            } else {
                tree[vx][vy] = tree[vx * 2][vy] + tree[vx * 2 + 1][vy];
            }
            return;
        }
        int my = (ly + ry) / 2;
        if (y <= my) {
            set_y(vx, lx, rx, vy * 2, ly, my, y, value);
        } else {
            set_y(vx, lx, rx, vy * 2 + 1, my + 1, ry, y, value);
        }
        tree[vx][vy] = tree[vx][vy * 2] + tree[vx][vy * 2 + 1];
    }

    void set_x(int vx, int lx, int rx, int x, int y, int value) {
        if (lx != rx) {
            int mx = (lx + rx) / 2;
            if (x <= mx) {
                set_x(vx * 2, lx, mx, x, y, value);
            } else {
                set_x(vx * 2 + 1, mx + 1, rx, x, y, value);
            }
        }
        set_y(vx, lx, rx, 1, 1, m, y, value);
    }

    int query_y(int vx, int vy, int ly, int ry, int y1, int y2) {
        if (y1 > y2) {
            return 0;
        }
        if (y1 == ly && y2 == ry) {
            return tree[vx][vy];
        }
        int my = (ly + ry) / 2;
        return query_y(vx, vy * 2, ly, my, y1, min(y2, my)) +
               query_y(vx, vy * 2 + 1, my + 1, ry, max(y1, my + 1), y2);
    }

    int query_x(int vx, int lx, int rx, int x1, int x2, int y1, int y2) {
        if (x1 > x2) {
            return 0;
        }
        if (x1 == lx && x2 == rx) {
            return query_y(vx, 1, 1, m, y1, y2);
        }
        int mx = (lx + rx) / 2;
        return query_x(vx * 2, lx, mx, x1, min(x2, mx), y1, y2) +
               query_x(vx * 2 + 1, mx + 1, rx, max(x1, mx + 1), x2, y1, y2);
    }
};

signed main() {
    int n, m, q;
    cin >> n >> m >> q;
    SegTree2D tree(n, m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> tree.a[i][j];
        }
    }
    tree.build_x(1, 1, n);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y, v;
            cin >> x >> y >> v;
            tree.a[x][y] = v;
            tree.set_x(1, 1, n, x, y, v);
        } else {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << tree.query_x(1, 1, n, x1, x2, y1, y2) << '\n';
        }
    }
    return 0;
}
