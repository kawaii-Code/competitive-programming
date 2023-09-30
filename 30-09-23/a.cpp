#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        result++;

        int next;
        cin >> next;
        if (next == result) {
            result++;
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
