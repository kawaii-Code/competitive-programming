#include <iostream>
#include <string>

using namespace std;

void solve() {
    int n;
    cin >> n;

    int result = 1;
    int min = -1;
    for (int i = 0; i < n; i++) {
        int digit;
        cin >> digit;

        if (digit < min || min == -1) {
            if (min == -1) {
                min = digit;
                continue;
            }
            result *= min;
            min = digit;
        } else {
            result *= digit;
        }
    }

    cout << result * (min + 1) << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
