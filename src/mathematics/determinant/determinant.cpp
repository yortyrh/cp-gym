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
    vector<vector<double>> a(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    int pivot_row = 0;
    double det = 1.0;
    for (int column = 0; column < n && pivot_row < n; ++column) {
        int best = pivot_row;
        for (int row = pivot_row + 1; row < n; ++row) {
            if (fabs(a[row][column]) > fabs(a[best][column])) {
                best = row;
            }
        }
        if (fabs(a[best][column]) < linear_algebra_epsilon) {
            det = 0.0;
            continue;
        }
        if (best != pivot_row) {
            swap(a[best], a[pivot_row]);
            det = -det;
        }
        double pivot = a[pivot_row][column];
        det *= pivot;
        for (int row = pivot_row + 1; row < n; ++row) {
            double factor = a[row][column] / pivot;
            for (int index = column; index < n; ++index) {
                a[row][index] -= factor * a[pivot_row][index];
            }
        }
        ++pivot_row;
    }
    cout << det << '\n';
    return 0;
}
