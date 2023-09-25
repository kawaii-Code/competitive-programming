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

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int last = 0;
    int check = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (a[i] > last) {
            if (a[check] != i + 1) {
                cout << "NO" << "\n";
                return;
            }
            check++;
            last++;
        }
    }

    cout << "YES" << "\n";
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
