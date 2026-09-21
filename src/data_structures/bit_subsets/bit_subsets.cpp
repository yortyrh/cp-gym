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
    int q;
    cin >> q;
    while (q--) {
        int mask;
        cin >> mask;
        int sub = mask;
        bool first = true;
        do {
            if (!first) {
                cout << ' ';
            }
            first = false;
            cout << sub;
            sub = (sub - 1) & mask;
        } while (sub != mask);
        cout << '\n';
    }
    return 0;
}
