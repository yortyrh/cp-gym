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
    string lhs, rhs;
    cin >> lhs >> rhs;
    int n = lhs.size();
    int m = rhs.size();
    vector<vector<int>> distance(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
        distance[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
        distance[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int cost = lhs[i - 1] == rhs[j - 1] ? 0 : 1;
            distance[i][j] = min({distance[i - 1][j] + 1, distance[i][j - 1] + 1,
                                  distance[i - 1][j - 1] + cost});
        }
    }
    cout << distance[n][m] << '\n';
    return 0;
}
