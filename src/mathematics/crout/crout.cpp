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

const double linear_algebra_epsilon = 1e-9;

signed main() {
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<vector<double>> matrix(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }
    vector<vector<double>> lower(n, vector<double>(n, 0.0));
    vector<vector<double>> upper(n, vector<double>(n, 0.0));
    for (int i = 0; i < n; ++i) {
        upper[i][i] = 1.0;
    }
    double det = 1.0;
    for (int j = 0; j < n; ++j) {
        for (int i = j; i < n; ++i) {
            double sum = matrix[i][j];
            for (int k = 0; k < j; ++k) {
                sum -= lower[i][k] * upper[k][j];
            }
            lower[i][j] = sum;
        }
        if (fabs(lower[j][j]) < linear_algebra_epsilon) {
            cout << 0.0 << '\n';
            return 0;
        }
        det *= lower[j][j];
        for (int i = j + 1; i < n; ++i) {
            double sum = matrix[j][i];
            for (int k = 0; k < j; ++k) {
                sum -= lower[j][k] * upper[k][i];
            }
            upper[j][i] = sum / lower[j][j];
        }
    }
    cout << det << '\n';
    return 0;
}
