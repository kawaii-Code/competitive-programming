#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define debug(x) std::cout << #x << " = " << x << "\n"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve() {
    int n;
    cin >> n;
    ull sum = 0;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        sum += next;
    }

    if (sum % 2 == 0) {
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
