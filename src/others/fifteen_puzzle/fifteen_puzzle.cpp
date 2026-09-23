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

signed main() {
    vector<int> tiles(16);
    for (int i = 0; i < 16; ++i) {
        cin >> tiles[i];
    }
    int inversions = 0;
    int blank_row = 0;
    for (int i = 0; i < 16; ++i) {
        if (tiles[i] == 0) {
            blank_row = i / 4;
            continue;
        }
        for (int j = i + 1; j < 16; ++j) {
            if (tiles[j] != 0 && tiles[i] > tiles[j]) {
                ++inversions;
            }
        }
    }
    cout << ((inversions + blank_row) % 2 == 1 ? "YES" : "NO") << '\n';
    return 0;
}
