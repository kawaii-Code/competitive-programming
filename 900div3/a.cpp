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

    bool yes = false;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        if (next == k) {
            yes = true;
        }
    }

    if (yes) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
