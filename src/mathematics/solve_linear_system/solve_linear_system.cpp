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

const double linear_algebra_epsilon = 1e-9;

signed main() {
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<vector<double>> a(n, vector<double>(n + 1));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i][n];
    }
    int pivot_row = 0;
    for (int column = 0; column < n && pivot_row < n; ++column) {
        int best = pivot_row;
        for (int row = pivot_row + 1; row < n; ++row) {
            if (fabs(a[row][column]) > fabs(a[best][column])) {
                best = row;
            }
        }
        if (fabs(a[best][column]) < linear_algebra_epsilon) {
            continue;
        }
        if (best != pivot_row) {
            swap(a[best], a[pivot_row]);
        }
        double pivot = a[pivot_row][column];
        for (int row = pivot_row + 1; row < n; ++row) {
            double factor = a[row][column] / pivot;
            for (int index = column; index <= n; ++index) {
                a[row][index] -= factor * a[pivot_row][index];
            }
        }
        ++pivot_row;
    }
    if (pivot_row < n) {
        cout << -1 << '\n';
        return 0;
    }
    vector<double> x(n);
    for (int row = n - 1; row >= 0; --row) {
        double value = a[row][n];
        for (int column = row + 1; column < n; ++column) {
            value -= a[row][column] * x[column];
        }
        if (fabs(a[row][row]) < linear_algebra_epsilon) {
            cout << -1 << '\n';
            return 0;
        }
        x[row] = value / a[row][row];
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << x[i];
    }
    cout << '\n';
    return 0;
}
