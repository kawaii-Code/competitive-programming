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
#include <cmath>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define debug(x) std::cout << #x << " = " << x << "\n"

void solve2(ull n) {
    ull e = n - 1;
    for (ull k = 2; k <= 1'000'000+1 / 5; k++) {
        ull limit = k*k + k;
        if (e < limit) {
            break;
        }
        if (e == limit) {
            cout << "YES\n";
            return;
        }

        ull mn = 1;
        ull t = k * (pow(k, mn) - 1) / (k - 1);
        while (e > t) {
            mn++;
            t = k * (pow(k, mn) - 1) / (k - 1);
        }

        if (e == t) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

void solve() {
    ull n;
    cin >> n;
    solve2(n);

    ull e = n - 1;
    ull left = 2ULL;
    ull right = 1'000'000'000'000ULL;
    while (left < right) {
        ull k = (left + right) / 2;
        ull limit = k*k + k;
        if (e < limit) {
            right = k - 1;
        } else if (e == limit) {
            cout << "YES\n";
            return;
        } else {
            ull x = round(log(e * (k - 1) + k) / log(k)) - 1;
            ull te = k * (pow(k, x) - 1) / (k - 1);

            debug(k);
            debug(x);
            debug(te);
            if (e == te) {
                cout << "YES\b";
                return;
            } else {
                left++;
            }
        }
    }

    ull k = left;
    ull x = round(log(e * (k - 1) + k) / log(k)) - 1;
    ull te = k * (pow(k, x)) / (k - 1);
    if (te == e) {
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
