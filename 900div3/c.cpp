#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;

void solve() {
    ull n, k, x;
    cin >> n >> k >> x;

    ull sum = n * (n + 1) / 2;
    ull ksum = k * (k + 1) / 2;
    ull noksum = (n - k) * ((n - k) + 1) / 2;

    if (x < ksum) {
        cout << "NO\n";
        return;
    }

    if (sum >= x && sum - noksum >= x) {
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
