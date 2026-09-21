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

struct Pt {
    int x, y;
};

int dist2(const Pt& a, const Pt& b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int rec(vector<Pt>& p, int l, int r) {
    if (r - l <= 3) {
        int best = 4e18;
        for (int i = l; i < r; ++i) {
            for (int j = i + 1; j < r; ++j) {
                best = min(best, dist2(p[i], p[j]));
            }
        }
        sort(p.begin() + l, p.begin() + r, [](const Pt& u, const Pt& v) { return u.y < v.y; });
        return best;
    }
    int m = (l + r) / 2;
    int mid_x = p[m].x;
    int d = min(rec(p, l, m), rec(p, m, r));
    inplace_merge(p.begin() + l, p.begin() + m, p.begin() + r,
                  [](const Pt& u, const Pt& v) { return u.y < v.y; });
    vector<Pt> strip;
    for (int i = l; i < r; ++i) {
        int dx = p[i].x - mid_x;
        if (dx * dx < d) {
            strip.push_back(p[i]);
        }
    }
    int sz = strip.size();
    for (int i = 0; i < sz; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            int dy = strip[j].y - strip[i].y;
            if (dy * dy >= d) {
                break;
            }
            d = min(d, dist2(strip[i], strip[j]));
        }
    }
    return d;
}

signed main() {
    int n;
    cin >> n;
    vector<Pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }
    sort(p.begin(), p.end(), [](const Pt& u, const Pt& v) {
        if (u.x != v.x) {
            return u.x < v.x;
        }
        return u.y < v.y;
    });
    cout << rec(p, 0, n) << '\n';
    return 0;
}
