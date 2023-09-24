#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    int result = 0;
    int erase_left = 0;
    for (int i = 0; i < n; i++) {
        char next;
        cin >> next;

        if (erase_left > 0) {
            erase_left--;
            continue;
        }

        if (next == 'B') {
            result++;
            erase_left = k - 1;
        }
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
