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
    int n, m;
    cin >> n >> m;
    vector<vector<long double>> lap(n + 1, vector<long double>(n + 1));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            continue;
        }
        lap[u][u] += 1;
        lap[v][v] += 1;
        lap[u][v] -= 1;
        lap[v][u] -= 1;
    }
    if (n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    int dim = n - 1;
    vector<vector<long double>> mat(dim, vector<long double>(dim));
    for (int i = 0; i < dim; ++i) {
        for (int j = 0; j < dim; ++j) {
            mat[i][j] = lap[i + 2][j + 2];
        }
    }
    long double det = 1;
    for (int col = 0; col < dim; ++col) {
        int pivot = col;
        for (int row = col + 1; row < dim; ++row) {
            if (fabsl(mat[row][col]) > fabsl(mat[pivot][col])) {
                pivot = row;
            }
        }
        if (fabsl(mat[pivot][col]) < 1e-12L) {
            det = 0;
            break;
        }
        if (pivot != col) {
            swap(mat[pivot], mat[col]);
            det = -det;
        }
        det *= mat[col][col];
        for (int row = col + 1; row < dim; ++row) {
            long double factor = mat[row][col] / mat[col][col];
            for (int j = col; j < dim; ++j) {
                mat[row][j] -= factor * mat[col][j];
            }
        }
    }
    int ans = llroundl(det);
    if (ans < 0) {
        ans = -ans;
    }
    cout << ans << '\n';
    return 0;
}
