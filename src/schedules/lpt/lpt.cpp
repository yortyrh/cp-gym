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
    int n, m;
    cin >> n >> m;
    vector<int> durations(n);
    for (int i = 0; i < n; ++i) {
        cin >> durations[i];
    }
    sort(durations.begin(), durations.end(), greater<int>());
    priority_queue<int, vector<int>, greater<int>> load;
    for (int i = 0; i < m; ++i) {
        load.push(0);
    }
    for (int duration : durations) {
        int least = load.top();
        load.pop();
        load.push(least + duration);
    }
    int answer = 0;
    while (!load.empty()) {
        answer = max(answer, load.top());
        load.pop();
    }
    cout << answer << '\n';
    return 0;
}
