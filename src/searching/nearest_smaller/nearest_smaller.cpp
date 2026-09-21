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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> st;
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        while (!st.empty() && a[st.back()] >= a[i]) {
            st.pop_back();
        }
        ans[i] = st.empty() ? 0 : st.back() + 1;
        st.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
