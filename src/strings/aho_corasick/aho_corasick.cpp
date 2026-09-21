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

struct AhoCorasick {
    static constexpr int alpha = 26;
    struct Node {
        array<int, 26> next;
        int link;
        vector<int> outputs;
        Node() {
            next.fill(-1);
            link = 0;
        }
    };

    vector<Node> nodes;
    int pattern_count;

    AhoCorasick() : nodes(1), pattern_count(0) {}

    void add_pattern(const string& pattern) {
        int node = 0;
        for (char character : pattern) {
            int letter = character - 'a';
            if (nodes[node].next[letter] == -1) {
                nodes[node].next[letter] = nodes.size();
                nodes.push_back(Node());
            }
            node = nodes[node].next[letter];
        }
        nodes[node].outputs.push_back(pattern_count);
        ++pattern_count;
    }

    void build() {
        queue<int> pending;
        for (int letter = 0; letter < alpha; ++letter) {
            if (nodes[0].next[letter] == -1) {
                nodes[0].next[letter] = 0;
            } else {
                pending.push(nodes[0].next[letter]);
            }
        }
        while (!pending.empty()) {
            int vertex = pending.front();
            pending.pop();
            for (int letter = 0; letter < alpha; ++letter) {
                int& next = nodes[vertex].next[letter];
                if (next == -1) {
                    next = nodes[nodes[vertex].link].next[letter];
                    continue;
                }
                nodes[next].link = nodes[nodes[vertex].link].next[letter];
                const vector<int>& from = nodes[nodes[next].link].outputs;
                nodes[next].outputs.insert(nodes[next].outputs.end(), from.begin(), from.end());
                pending.push(next);
            }
        }
    }

    vector<int> count_in(const string& text) const {
        vector<int> occurrences(pattern_count);
        int node = 0;
        for (char character : text) {
            int letter = character - 'a';
            node = nodes[node].next[letter];
            for (int pattern : nodes[node].outputs) {
                ++occurrences[pattern];
            }
        }
        return occurrences;
    }
};

signed main() {
    int k;
    cin >> k;
    AhoCorasick automaton;
    for (int i = 0; i < k; ++i) {
        string pattern;
        cin >> pattern;
        automaton.add_pattern(pattern);
    }
    string text;
    cin >> text;
    automaton.build();
    vector<int> occurrences = automaton.count_in(text);
    for (int value : occurrences) {
        cout << value << '\n';
    }
    return 0;
}
