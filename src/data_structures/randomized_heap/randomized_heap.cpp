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

mt19937 rng(2);

struct Node {
    int val;
    Node *l, *r;
    explicit Node(int v) : val(v), l(nullptr), r(nullptr) {}
};

Node* meld(Node* a, Node* b) {
    if (!a) {
        return b;
    }
    if (!b) {
        return a;
    }
    if (b->val < a->val) {
        swap(a, b);
    }
    if ((rng() & 1U) != 0U) {
        swap(a->l, a->r);
    }
    a->r = meld(a->r, b);
    return a;
}

signed main() {
    int n, q;
    cin >> n >> q;
    vector<Node*> heap(n + 1, nullptr);
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int i, x;
            cin >> i >> x;
            heap[i] = meld(heap[i], new Node(x));
        } else if (type == 2) {
            int i;
            cin >> i;
            cout << heap[i]->val << '\n';
        } else if (type == 3) {
            int i;
            cin >> i;
            cout << heap[i]->val << '\n';
            Node* old = heap[i];
            heap[i] = meld(old->l, old->r);
            delete old;
        } else {
            int i, j;
            cin >> i >> j;
            heap[i] = meld(heap[i], heap[j]);
            heap[j] = nullptr;
        }
    }
    return 0;
}
