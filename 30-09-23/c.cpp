#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n);

    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    ll result = 0;
    for (ll i = n - 1; i >= 0; i--) {
        ll current = sum + a[i];
        if (i % 2 == 1) {
            current -= a[i];
        }
        if (current > result) {
            result = current;
        }

        if (a[i] > 0) {
            sum += a[i];
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
