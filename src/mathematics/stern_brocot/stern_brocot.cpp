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
    int numerator, denominator;
    cin >> numerator >> denominator;
    string path;
    int left_n = 0;
    int left_d = 1;
    int right_n = 1;
    int right_d = 0;
    while (true) {
        int mid_n = left_n + right_n;
        int mid_d = left_d + right_d;
        if (mid_n == numerator && mid_d == denominator) {
            break;
        }
        if (numerator * mid_d < denominator * mid_n) {
            path.push_back('L');
            right_n = mid_n;
            right_d = mid_d;
        } else {
            path.push_back('R');
            left_n = mid_n;
            left_d = mid_d;
        }
    }
    cout << path << '\n';
    return 0;
}
