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

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
    bool operator==(const Point& other) const { return x == other.x && y == other.y; }
};

int cross(Point origin, Point lhs, Point rhs) {
    return (lhs.x - origin.x) * (rhs.y - origin.y) - (lhs.y - origin.y) * (rhs.x - origin.x);
}

signed main() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    int count = points.size();
    if (count <= 2) {
        cout << count << '\n';
        for (auto p : points) {
            cout << p.x << ' ' << p.y << '\n';
        }
        return 0;
    }
    vector<Point> lower;
    vector<Point> upper;
    auto push = [&](vector<Point>& hull, Point point) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), point) <= 0) {
            hull.pop_back();
        }
        hull.push_back(point);
    };
    for (auto point : points) {
        push(lower, point);
    }
    for (int i = count - 1; i >= 0; --i) {
        push(upper, points[i]);
    }
    lower.pop_back();
    upper.pop_back();
    lower.insert(lower.end(), upper.begin(), upper.end());
    cout << lower.size() << '\n';
    for (auto p : lower) {
        cout << p.x << ' ' << p.y << '\n';
    }
    return 0;
}
