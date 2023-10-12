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
    int n, m;
    cin >> n >> m;

    string s, x;
    cin >> x >> s;

    int count = 0;
    while (n <= 50) {
        if (x.find(s) != string::npos) {
            cout << count << "\n";
            return;
        }

        x += x;
        n *= 2;
        count++;
    }

    cout << -1 << "\n";
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
