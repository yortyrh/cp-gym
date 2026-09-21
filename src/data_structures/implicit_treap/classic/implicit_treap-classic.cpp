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

mt19937 rng(1);

struct Node {
    int val, sum, pri, sz;
    Node *l, *r;
    explicit Node(int v) : val(v), sum(v), pri(rng()), sz(1), l(nullptr), r(nullptr) {}
};

int sz(Node* t) { return t ? t->sz : 0; }
int sm(Node* t) { return t ? t->sum : 0; }

void pull(Node* t) {
    t->sz = 1 + sz(t->l) + sz(t->r);
    t->sum = t->val + sm(t->l) + sm(t->r);
}

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

signed main() {
    int q;
    cin >> q;
    Node* root = nullptr;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int p, x;
            cin >> p >> x;
            auto [left, right] = split(root, p - 1);
            root = merge(merge(left, new Node(x)), right);
        } else if (type == 2) {
            int p;
            cin >> p;
            auto [left, mid_right] = split(root, p - 1);
            auto [mid, right] = split(mid_right, 1);
            delete mid;
            root = merge(left, right);
        } else {
            int l, r;
            cin >> l >> r;
            auto [left, mid_right] = split(root, l - 1);
            auto [mid, right] = split(mid_right, r - l + 1);
            cout << sm(mid) << '\n';
            root = merge(merge(left, mid), right);
        }
    }
    return 0;
}
