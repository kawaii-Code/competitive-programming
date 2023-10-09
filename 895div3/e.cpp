#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int xor1 = 0;
    int xor0 = 0;
    for (int i = 0; i < n; i++) {
        char next;
        cin >> next;
        if (next == '0') {
            xor0 ^= a[i];
        } else {
            xor1 ^= a[i];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;

        if (tp == 1) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;

            for (int i = l; i <= r; i++) {
                xor0 ^= a[i];
                xor1 ^= a[i];
            }
        } else {
            int g;
            cin >> g;
            if (g == 0) {
                cout << xor0 << " ";
            } else {
                cout << xor1 << " ";
            }
        }
    }
    cout << "\n";
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
