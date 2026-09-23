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
    unordered_set<int> present;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        present.insert(value);
    }
    int candidate = 0;
    while (present.contains(candidate)) {
        ++candidate;
    }
    cout << candidate << '\n';
    return 0;
}
