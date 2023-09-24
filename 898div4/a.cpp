#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;

    if (s == "bca" || s == "cab") {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
