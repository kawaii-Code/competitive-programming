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

#define debug(x) std::cout << #x << " = " << x << "\n"

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;

    ll result = 0;
    ll penalty = 0;
    vector<int> t(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    
    int hc = h;
    for (int i = 0; i < m; i++) {
        hc -= t[i];
        if (hc >= 0) {
            result++;
            penalty += h - hc;
        } else {
            break;
        }
    }

    int ans = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> t[j];
        }

        ll s = 0;
        ll p = 0;
        sort(t.begin(), t.end());

        int hc = h;
        for (int i = 0; i < m; i++) {
            hc -= t[i];
            if (hc >= 0) {
                s++;
                p += h - hc;
            } else {
                break;
            }
        }

        if (s > result) {
            ans++;
        } else if (s == result) {
            if (p < penalty) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
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
