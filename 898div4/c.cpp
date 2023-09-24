#include <iostream>

using namespace std;

void solve() {
    size_t result = 0;
    for (int y = 0; y < 10; y++) {
        for (int x = 0; x < 10; x++) {
            char next;
            cin >> next;

            if (next != 'X') {
                continue;
            }

            if (x == 0 || x == 9 || y == 0 || y == 9) {
                result += 1;
            } else if (x == 1 || x == 8 || y == 1 || y == 8) {
                result += 2;
            } else if (x == 2 || x == 7 || y == 2 || y == 7) {
                result += 3;
            } else if (x == 3 || x == 6 || y == 3 || y == 6) {
                result += 4;
            } else {
                result += 5;
            }
        }
    }
    cout << result << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
