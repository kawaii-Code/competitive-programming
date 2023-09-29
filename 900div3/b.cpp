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

    int prev = 7;
    int cur = 11;
    cout << prev << " " << cur << " ";
    for (int i = 0; i < n; i++) {
        int next = cur + 1;
        while (((3 * next) % (prev + cur)) == 0) {
            next++;
        }

        cout << next << " ";
        prev = cur;
        cur = next;
    }
    cout << "\n";
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
