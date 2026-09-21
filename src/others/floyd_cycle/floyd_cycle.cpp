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

signed main() {
    int n, start;
    cin >> n >> start;
    vector<int> next_node(n);
    for (int i = 0; i < n; ++i) {
        cin >> next_node[i];
    }
    int tortoise = start;
    int hare = start;
    while (true) {
        tortoise = next_node[tortoise];
        hare = next_node[next_node[hare]];
        if (tortoise == hare) {
            break;
        }
    }
    int mu = start;
    while (mu != tortoise) {
        mu = next_node[mu];
        tortoise = next_node[tortoise];
    }
    int lambda = 1;
    int cycle = next_node[mu];
    while (cycle != mu) {
        cycle = next_node[cycle];
        ++lambda;
    }
    cout << mu << ' ' << lambda << '\n';
    return 0;
}
