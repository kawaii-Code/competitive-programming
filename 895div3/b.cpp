#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

ll nod(ll x, ll y) {
    while (x != 0 && y != 0) {
        if (x > y) {
            x %= y;
        } else {
            y %= x;
        }
    }

    return x + y;
}

ll nok(ll x, ll y) {
    return (x * y) / nod(x, y);
}

void solve() {
    ll n, x, y;
    cin >> n >> x >> y;

    x /= nod(x, y);
    y /= nod(x, y);
    ll nx = n / x;
    ll ny = n / y;
    ll sum = nx * (nx + n) / 2;
    sum -= ny * (1 + ny) / 2;

    cout << sum << "\n";
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
