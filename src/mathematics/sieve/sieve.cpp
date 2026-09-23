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
    int n;
    cin >> n;
    vector<char> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int value = 2; value <= n / value; ++value) {
        if (prime[value]) {
            for (int multiple = value * value; multiple <= n; multiple += value) {
                prime[multiple] = 0;
            }
        }
    }
    bool first = true;
    for (int value = 2; value <= n; ++value) {
        if (prime[value]) {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << value;
        }
    }
    cout << '\n';
    return 0;
}
