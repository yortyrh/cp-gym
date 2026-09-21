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

struct Interval {
    int begin, end;
};

signed main() {
    int from, to, n;
    cin >> from >> to >> n;
    vector<Interval> intervals(n);
    for (int i = 0; i < n; ++i) {
        cin >> intervals[i].begin >> intervals[i].end;
    }
    sort(intervals.begin(), intervals.end(),
         [](const Interval& lhs, const Interval& rhs) { return lhs.begin < rhs.begin; });
    int used = 0;
    int index = 0;
    int covered = from;
    bool ok = true;
    while (covered < to) {
        int best_end = covered;
        while (index < n && intervals[index].begin <= covered) {
            best_end = max(best_end, intervals[index].end);
            ++index;
        }
        if (best_end == covered) {
            ok = false;
            break;
        }
        covered = best_end;
        ++used;
    }
    if (!ok) {
        cout << -1 << '\n';
    } else {
        cout << used << '\n';
    }
    return 0;
}
