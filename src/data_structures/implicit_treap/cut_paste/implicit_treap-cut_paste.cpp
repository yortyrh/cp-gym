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

mt19937 rng(1);

struct Node {
    int val, pri, sz;
    Node *l, *r;
    explicit Node(int v) : val(v), pri(rng()), sz(1), l(nullptr), r(nullptr) {}
};

int sz(Node* t) { return t ? t->sz : 0; }

void pull(Node* t) { t->sz = 1 + sz(t->l) + sz(t->r); }

Node* merge(Node* a, Node* b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    if (a->pri < b->pri) {
        a->r = merge(a->r, b);
        pull(a);
        return a;
    }
    b->l = merge(a, b->l);
    pull(b);
    return b;
}

pair<Node*, Node*> split(Node* t, int count) {
    if (!t) {
        return {nullptr, nullptr};
    }
    if (sz(t->l) >= count) {
        auto [left, right] = split(t->l, count);
        t->l = right;
        pull(t);
        return {left, t};
    }
    auto [left, right] = split(t->r, count - sz(t->l) - 1);
    t->r = left;
    pull(t);
    return {t, right};
}

void collect(Node* t, vector<int>& out) {
    if (!t) {
        return;
    }
    collect(t->l, out);
    out.push_back(t->val);
    collect(t->r, out);
}

signed main() {
    int n, q;
    cin >> n >> q;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = merge(root, new Node(x));
    }
    while (q--) {
        int l, r, p;
        cin >> l >> r >> p;
        auto [left, mid_right] = split(root, l - 1);
        auto [mid, right] = split(mid_right, r - l + 1);
        root = merge(left, right);
        auto [pref, rest] = split(root, p);
        root = merge(merge(pref, mid), rest);
    }
    vector<int> out;
    collect(root, out);
    int first = 1;
    for (int x : out) {
        if (!first) {
            cout << ' ';
        }
        first = 0;
        cout << x;
    }
    cout << '\n';
    return 0;
}
