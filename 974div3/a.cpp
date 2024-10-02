#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define debug(x) std::cout << #x << " = " << x << std::endl

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve() {
    int k, n;
    int ans = 0;
    cin >> n;
    cin >> k;

    int g = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a >= k) {
            g += a;
        } else if (a == 0) {
            if (g != 0) {
                g -= 1;
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
