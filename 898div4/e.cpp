// DOESN'T WORK

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;

bool is_correct(int height, int max, vector<int> &heights, int n) {
    int needed = height * n;
    for (int i = 0; i < n; i++) {
        if (heights[i] < height) {
            needed -= heights[i];
        } else {
            needed -= height;
        }
    }
    return needed <= max;
}

void solve() {
    int n, x;
    cin >> n >> x;

    ull sum = 0;
    vector<int> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        sum += height[i];
    }

    int result = (x + sum) / n;
    while (!is_correct(result, x, height, n)) {
        result--;
    }
    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
