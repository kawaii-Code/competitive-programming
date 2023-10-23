#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define debug(x) std::cout << #x << " = " << x << "\n"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

void solve() {
    string s;
    cin >> s;

    bool c = false;
    int lastInc = s.size() - 1;
    for (int i = s.size() - 1; i > 0; i--) {
        while (s[i] == '9') {
            if (i == 0) {
                c = true;
                break;
            }
            lastInc = i - 1;
            if (s[i - 1] != '9') {
                s[i - 1]++;
            }
            i--;
        }

        if (c) {
            break;
        }

        if (s[i] != '9' && s[i] >= '5') {
            lastInc = i - 1;
            s[i - 1]++;
        }
    }

    if (s[0] >= '5') {
        cout << '1';
        for (int i = 0; i < s.size(); i++) {
            cout << '0';
        }
        cout << "\n";
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (i <= lastInc) {
                cout << s[i];
            } else {
                cout << '0';
            }
        }
        cout << "\n";
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
