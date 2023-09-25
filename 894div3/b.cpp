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

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> c(1);
    c[0] = b[0];
    for (int i = 1; i < n; i++) {
        if (c[c.size() - 1] <= b[i]) {
            c.push_back(b[i]);
        } else {
            c.push_back(b[i]);
            i--;
        }
    }

    cout << c.size() << "\n";
    for (int item : c) {
        cout << item << " ";
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
