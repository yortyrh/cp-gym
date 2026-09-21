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

int quick_select(vector<int>& values, int rank) {
    int begin = 0;
    int end = values.size();
    while (true) {
        int pivot = values[begin + (end - begin) / 2];
        int less = begin;
        int current = begin;
        int greater = end;
        while (current < greater) {
            if (values[current] < pivot) {
                swap(values[less], values[current]);
                ++less;
                ++current;
            } else if (pivot < values[current]) {
                --greater;
                swap(values[current], values[greater]);
            } else {
                ++current;
            }
        }
        if (rank < less) {
            end = less;
        } else if (rank >= greater) {
            begin = greater;
        } else {
            return values[rank];
        }
    }
}

signed main() {
    int n, rank;
    cin >> n >> rank;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    cout << quick_select(values, rank) << '\n';
    return 0;
}
