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

struct SuffixTree {
    struct Node {
        string label;
        map<char, int> children;
    };

    vector<Node> nodes;

    explicit SuffixTree(const string& text) {
        nodes.push_back(Node());
        int n = text.size();
        for (int suffix = 0; suffix < n; ++suffix) {
            insert(text.substr(suffix));
        }
    }

    void insert(const string& suffix) {
        int node = 0;
        int index = 0;
        int n = suffix.size();
        while (index < n) {
            char character = suffix[index];
            auto found = nodes[node].children.find(character);
            if (found == nodes[node].children.end()) {
                int next = nodes.size();
                nodes.push_back(Node{suffix.substr(index), {}});
                nodes[node].children[character] = next;
                return;
            }
            int child = found->second;
            string label = nodes[child].label;
            int match = 0;
            int label_n = label.size();
            while (match < label_n && index + match < n && label[match] == suffix[index + match]) {
                ++match;
            }
            if (match == label_n) {
                node = child;
                index += match;
                continue;
            }
            int split = nodes.size();
            map<char, int> old_children = nodes[child].children;
            nodes.push_back(Node{label.substr(0, match), {}});
            int rest = nodes.size();
            nodes.push_back(Node{label.substr(match), old_children});
            nodes[split].children[label[match]] = rest;
            int leftover = nodes.size();
            nodes.push_back(Node{suffix.substr(index + match), {}});
            nodes[split].children[suffix[index + match]] = leftover;
            nodes[node].children[character] = split;
            return;
        }
    }

    bool contains(const string& pattern) const {
        int node = 0;
        int offset = 0;
        for (char character : pattern) {
            int label_n = nodes[node].label.size();
            if (offset == label_n) {
                auto found = nodes[node].children.find(character);
                if (found == nodes[node].children.end()) {
                    return false;
                }
                node = found->second;
                offset = 0;
            }
            int cur_n = nodes[node].label.size();
            if (offset >= cur_n || nodes[node].label[offset] != character) {
                return false;
            }
            ++offset;
        }
        return true;
    }
};

signed main() {
    string s;
    int q;
    cin >> s >> q;
    SuffixTree tree(s);
    while (q--) {
        string t;
        cin >> t;
        cout << (tree.contains(t) ? "YES" : "NO") << '\n';
    }
    return 0;
}
