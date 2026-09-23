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

void merge_sort(vector<int>& values, vector<int>& buffer, int begin, int end) {
    if (end - begin <= 1) {
        return;
    }
    int mid = begin + (end - begin) / 2;
    merge_sort(values, buffer, begin, mid);
    merge_sort(values, buffer, mid, end);
    int left = begin;
    int right = mid;
    int out = begin;
    while (left < mid && right < end) {
        if (values[left] <= values[right]) {
            buffer[out++] = values[left++];
        } else {
            buffer[out++] = values[right++];
        }
    }
    while (left < mid) {
        buffer[out++] = values[left++];
    }
    while (right < end) {
        buffer[out++] = values[right++];
    }
    for (int i = begin; i < end; ++i) {
        values[i] = buffer[i];
    }
}

signed main() {
    int n;
    cin >> n;
    vector<int> values(n);
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    vector<int> buffer(n);
    merge_sort(values, buffer, 0, n);
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << values[i];
    }
    cout << '\n';
    return 0;
}
