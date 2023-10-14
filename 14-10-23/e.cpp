#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n);
    b[n-1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (i + a[i] >= n) {
            b[i] = b[i+1] + 1;
        } else {
            b[i] = min(b[i + a[i]] - a[i] - i, b[i+1] + 1);
        }
    }

    cout << b[0] << "\n";
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
