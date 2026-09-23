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

struct Job {
    int first, second, index;
};

signed main() {
    int n;
    cin >> n;
    vector<Job> first_group, second_group;
    for (int i = 0; i < n; ++i) {
        Job job;
        cin >> job.first >> job.second;
        job.index = i;
        if (job.first <= job.second) {
            first_group.push_back(job);
        } else {
            second_group.push_back(job);
        }
    }
    sort(first_group.begin(), first_group.end(),
         [](const Job& lhs, const Job& rhs) { return lhs.first < rhs.first; });
    sort(second_group.begin(), second_group.end(),
         [](const Job& lhs, const Job& rhs) { return lhs.second < rhs.second; });
    reverse(second_group.begin(), second_group.end());
    bool printed = false;
    for (const auto& job : first_group) {
        if (printed) {
            cout << ' ';
        }
        printed = true;
        cout << job.index;
    }
    for (const auto& job : second_group) {
        if (printed) {
            cout << ' ';
        }
        printed = true;
        cout << job.index;
    }
    cout << '\n';
    return 0;
}
