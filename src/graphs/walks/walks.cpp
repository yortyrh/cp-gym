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

vector<vector<int>> multiply_square(const vector<vector<int>>& lhs, const vector<vector<int>>& rhs) {
    int n = lhs.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                result[i][j] += lhs[i][k] * rhs[k][j];
            }
        }
    }
    return result;
}

signed main() {
    int n, length;
    cin >> n >> length;
    vector<vector<int>> adjacency(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> adjacency[i][j];
        }
    }
    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    while (length > 0) {
        if ((length & 1) != 0) {
            result = multiply_square(result, adjacency);
        }
        adjacency = multiply_square(adjacency, adjacency);
        length >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j > 0) {
                cout << ' ';
            }
            cout << result[i][j];
        }
        cout << '\n';
    }
    return 0;
}
