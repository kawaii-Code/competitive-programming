#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;

int answer(int height, int max, vector<int> &heights, int n) {
    int needed = height * n;
    for (int i = 0; i < n; i++) {
        if (heights[i] < height) {
            needed -= heights[i];
        } else {
            needed -= height;
        }
    }
    return needed;
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

    int left = x / n;
    int right = (x + sum) / n;
    int previousMiddle = -1;
    while (left < right) {
        int middle = (left + right) / 2;
        if (middle == previousMiddle) {
            break;
        }
        previousMiddle = middle;

        int needed = answer(middle, x, height, n);
        if (needed < x) {
            left = middle + 1;
        } else if (needed > x) {
            right = middle - 1;
        } else {
            cout << middle << "\n";
            return;
        }
    }
    cout << right << "\n";
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
