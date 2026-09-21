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

struct Job {
    int duration, weight, index;
};

signed main() {
    int n;
    cin >> n;
    vector<Job> jobs(n);
    for (int i = 0; i < n; ++i) {
        cin >> jobs[i].duration >> jobs[i].weight;
        jobs[i].index = i;
    }
    sort(jobs.begin(), jobs.end(), [](const Job& lhs, const Job& rhs) {
        return lhs.duration * rhs.weight < rhs.duration * lhs.weight;
    });
    for (int i = 0; i < n; ++i) {
        if (i) {
            cout << ' ';
        }
        cout << jobs[i].index;
    }
    cout << '\n';
    return 0;
}
