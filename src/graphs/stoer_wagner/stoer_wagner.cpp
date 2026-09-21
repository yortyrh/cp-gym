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
    int n;
    cin >> n;
    vector<vector<int>> weight(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> weight[i][j];
        }
    }
    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }
    vector<int> merged(n, 0);
    int best = 4e18;
    for (int phase = 0; phase + 1 < n; ++phase) {
        vector<int> added(n, 0);
        vector<char> in_set(n, 0);
        int previous = -1;
        int last = -1;
        for (int step = 0; step < n - phase; ++step) {
            int select = -1;
            for (int vertex = 0; vertex < n; ++vertex) {
                if (merged[vertex] != 0 || in_set[vertex] != 0) {
                    continue;
                }
                if (select == -1 || added[vertex] > added[select]) {
                    select = vertex;
                }
            }
            previous = last;
            last = select;
            in_set[select] = 1;
            for (int vertex = 0; vertex < n; ++vertex) {
                if (merged[vertex] == 0 && in_set[vertex] == 0) {
                    added[vertex] += weight[select][vertex];
                }
            }
        }
        best = min(best, added[last]);
        merged[last] = 1;
        for (int vertex = 0; vertex < n; ++vertex) {
            weight[previous][vertex] += weight[last][vertex];
            weight[vertex][previous] = weight[previous][vertex];
        }
    }
    cout << best << '\n';
    return 0;
}
