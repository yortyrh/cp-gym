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

signed main() {
    int length, m;
    cin >> length >> m;
    vector<int> points;
    points.push_back(0);
    points.push_back(length);
    for (int i = 0; i < m; ++i) {
        int cut;
        cin >> cut;
        points.push_back(cut);
    }
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
    int n = points.size();
    const int inf = 4e18;
    vector<vector<int>> cost(n, vector<int>(n));
    for (int span = 2; span < n; ++span) {
        for (int left = 0; left + span < n; ++left) {
            int right = left + span;
            int best = inf;
            for (int mid = left + 1; mid < right; ++mid) {
                best = min(best, cost[left][mid] + cost[mid][right]);
            }
            cost[left][right] = best + points[right] - points[left];
        }
    }
    cout << (n <= 1 ? 0 : cost[0][n - 1]) << '\n';
    return 0;
}
