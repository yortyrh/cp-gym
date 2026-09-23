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

int board_size;
vector<int> columns;
vector<vector<int>> solutions;

bool used(int row, int column) {
    for (int previous = 0; previous < row; ++previous) {
        if (columns[previous] == column || columns[previous] - previous == column - row ||
            columns[previous] + previous == column + row) {
            return true;
        }
    }
    return false;
}

void search(int row) {
    if (row == board_size) {
        solutions.push_back(columns);
        return;
    }
    for (int column = 0; column < board_size; ++column) {
        if (!used(row, column)) {
            columns[row] = column;
            search(row + 1);
        }
    }
}

signed main() {
    cin >> board_size;
    columns.assign(board_size, -1);
    search(0);
    cout << solutions.size() << '\n';
    for (const auto& solution : solutions) {
        for (int i = 0; i < board_size; ++i) {
            if (i) {
                cout << ' ';
            }
            cout << solution[i];
        }
        cout << '\n';
    }
    return 0;
}
