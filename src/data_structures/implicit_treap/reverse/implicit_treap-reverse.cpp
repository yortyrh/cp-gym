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
    int val, sum, pri, sz, rev;
    Node *l, *r;
    explicit Node(int v)
        : val(v), sum(v), pri(rng()), sz(1), rev(0), l(nullptr), r(nullptr) {}
};

int sz(Node* t) { return t ? t->sz : 0; }
int sm(Node* t) { return t ? t->sum : 0; }

void push(Node* t) {
    if (!t || !t->rev) {
        return;
    }
    swap(t->l, t->r);
    if (t->l) {
        t->l->rev ^= 1;
    }
    if (t->r) {
        t->r->rev ^= 1;
    }
    t->rev = 0;
}

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
    push(a);
    push(b);
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
    push(t);
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
    int n, q;
    cin >> n >> q;
    Node* root = nullptr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        root = merge(root, new Node(x));
    }
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        auto [left, mid_right] = split(root, l - 1);
        auto [mid, right] = split(mid_right, r - l + 1);
        if (type == 1) {
            if (mid) {
                mid->rev ^= 1;
            }
        } else {
            cout << sm(mid) << '\n';
        }
        root = merge(merge(left, mid), right);
    }
    return 0;
}
