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

struct MinStack {
    vector<pair<int, int>> st;

    void push(int value) {
        int current_min = st.empty() ? value : min(value, st.back().second);
        st.push_back({value, current_min});
    }

    void pop() { st.pop_back(); }

    int minimum() const { return st.back().second; }
};

signed main() {
    int q;
    cin >> q;
    MinStack stack;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            stack.push(x);
        } else if (type == 2) {
            stack.pop();
        } else {
            cout << stack.minimum() << '\n';
        }
    }
    return 0;
}
