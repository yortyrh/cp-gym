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

struct SuffixAutomaton {
    struct State {
        int length;
        int link;
        map<char, int> next;
        State() : length(0), link(-1) {}
    };

    vector<State> states;
    int last;

    SuffixAutomaton() {
        states.push_back(State());
        last = 0;
    }

    void extend(char character) {
        int current = states.size();
        states.push_back(State());
        states[current].length = states[last].length + 1;
        int p = last;
        while (p != -1 && !states[p].next.contains(character)) {
            states[p].next[character] = current;
            p = states[p].link;
        }
        if (p == -1) {
            states[current].link = 0;
        } else {
            int q = states[p].next[character];
            if (states[p].length + 1 == states[q].length) {
                states[current].link = q;
            } else {
                int clone = states.size();
                State copied = states[q];
                states.push_back(copied);
                states[clone].length = states[p].length + 1;
                while (p != -1 && states[p].next[character] == q) {
                    states[p].next[character] = clone;
                    p = states[p].link;
                }
                states[q].link = clone;
                states[current].link = clone;
            }
        }
        last = current;
    }

    explicit SuffixAutomaton(const string& text) : SuffixAutomaton() {
        for (char character : text) {
            extend(character);
        }
    }

    bool contains(const string& pattern) const {
        int state = 0;
        for (char character : pattern) {
            auto found = states[state].next.find(character);
            if (found == states[state].next.end()) {
                return false;
            }
            state = found->second;
        }
        return true;
    }

    int distinct_substrings() const {
        int total = 0;
        int state_count = states.size();
        for (int index = 1; index < state_count; ++index) {
            total += states[index].length - states[states[index].link].length;
        }
        return total;
    }
};

signed main() {
    string s;
    int q;
    cin >> s >> q;
    SuffixAutomaton automaton(s);
    cout << automaton.distinct_substrings() << '\n';
    while (q--) {
        string t;
        cin >> t;
        cout << (automaton.contains(t) ? "YES" : "NO") << '\n';
    }
    return 0;
}
