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

struct Node {
    int key, height, sz;
    Node *l, *r;
    explicit Node(int k) : key(k), height(1), sz(1), l(nullptr), r(nullptr) {}
};

int height_of(Node* t) { return t ? t->height : 0; }
int size_of(Node* t) { return t ? t->sz : 0; }

void pull(Node* t) {
    t->height = 1 + max(height_of(t->l), height_of(t->r));
    t->sz = 1 + size_of(t->l) + size_of(t->r);
}

int balance_of(Node* t) { return height_of(t->l) - height_of(t->r); }

Node* rotate_left(Node* t) {
    Node* child = t->r;
    t->r = child->l;
    child->l = t;
    pull(t);
    pull(child);
    return child;
}

Node* rotate_right(Node* t) {
    Node* child = t->l;
    t->l = child->r;
    child->r = t;
    pull(t);
    pull(child);
    return child;
}

Node* rebalance(Node* t) {
    pull(t);
    if (balance_of(t) > 1) {
        if (balance_of(t->l) < 0) {
            t->l = rotate_left(t->l);
        }
        return rotate_right(t);
    }
    if (balance_of(t) < -1) {
        if (balance_of(t->r) > 0) {
            t->r = rotate_right(t->r);
        }
        return rotate_left(t);
    }
    return t;
}

Node* insert_node(Node* t, int key) {
    if (!t) {
        return new Node(key);
    }
    if (key < t->key) {
        t->l = insert_node(t->l, key);
    } else if (t->key < key) {
        t->r = insert_node(t->r, key);
    } else {
        return t;
    }
    return rebalance(t);
}

Node* extract_min(Node* t, Node*& mn) {
    if (!t->l) {
        mn = t;
        return t->r;
    }
    t->l = extract_min(t->l, mn);
    return rebalance(t);
}

Node* erase_node(Node* t, int key) {
    if (!t) {
        return nullptr;
    }
    if (key < t->key) {
        t->l = erase_node(t->l, key);
    } else if (t->key < key) {
        t->r = erase_node(t->r, key);
    } else {
        if (!t->l) {
            Node* right = t->r;
            delete t;
            return right;
        }
        if (!t->r) {
            Node* left = t->l;
            delete t;
            return left;
        }
        Node* succ = nullptr;
        Node* right = extract_min(t->r, succ);
        succ->l = t->l;
        succ->r = right;
        delete t;
        return rebalance(succ);
    }
    return rebalance(t);
}

int kth_node(Node* t, int rank) {
    int left = size_of(t->l);
    if (rank < left) {
        return kth_node(t->l, rank);
    }
    if (rank == left) {
        return t->key;
    }
    return kth_node(t->r, rank - left - 1);
}

signed main() {
    int q;
    cin >> q;
    Node* root = nullptr;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            root = insert_node(root, x);
        } else if (type == 2) {
            int x;
            cin >> x;
            root = erase_node(root, x);
        } else {
            int k;
            cin >> k;
            if (k < 1 || k > size_of(root)) {
                cout << -1 << '\n';
            } else {
                cout << kth_node(root, k - 1) << '\n';
            }
        }
    }
    return 0;
}
