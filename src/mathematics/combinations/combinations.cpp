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
    int n, k;
    cin >> n >> k;
    vector<int> combination(k);
    for (int i = 0; i < k; ++i) {
        combination[i] = i;
    }
    while (true) {
        for (int i = 0; i < k; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << combination[i];
        }
        cout << '\n';
        int index = k;
        while (index > 0 && combination[index - 1] == n - k + index - 1) {
            --index;
        }
        if (index == 0) {
            break;
        }
        ++combination[index - 1];
        for (int j = index; j < k; ++j) {
            combination[j] = combination[j - 1] + 1;
        }
    }
    return 0;
}
