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

    int top() const { return st.back().first; }

    int minimum() const { return st.back().second; }

    bool empty() const { return st.empty(); }
};

struct MinQueue {
    MinStack front, back;

    void push(int value) { back.push(value); }

    void shift() {
        if (!front.empty()) {
            return;
        }
        while (!back.empty()) {
            front.push(back.top());
            back.pop();
        }
    }

    void pop() {
        shift();
        front.pop();
    }

    int minimum() {
        if (front.empty()) {
            return back.minimum();
        }
        if (back.empty()) {
            return front.minimum();
        }
        return min(front.minimum(), back.minimum());
    }
};

signed main() {
    int q;
    cin >> q;
    MinQueue queue;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queue.push(x);
        } else if (type == 2) {
            queue.pop();
        } else {
            cout << queue.minimum() << '\n';
        }
    }
    return 0;
}
