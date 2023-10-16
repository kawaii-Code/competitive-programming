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

bool is_win(char f[9], char p) {
    bool result = false;
    for (int i = 0; i < 3; i++) {
        result = true;
        for (int c = 0; c < 3; c++) {
            if (f[i*3 + c] != p) {
                result = false;
            }
        }

        if (result) {
            return result;
        }
    }

    for (int i = 0; i < 3; i++) {
        result = true;
        for (int c = 0; c < 3; c++) {
            if (f[c*3 + i] != p) {
                result = false;
            }
        }

        if (result) {
            return result;
        }
    }

    if (f[0] == f[4] && f[4] == f[8] && f[0] == p) {
        return true;
    }

    if (f[2] == f[4] && f[4] == f[6] && f[2] == p) {
        return true;
    }

    return false;
}

void solve() {
    char f[9];
    for (int i = 0; i < 9; i++) {
        cin >> f[i];
    }

    if (is_win(f, '+')) {
        cout << "+" << "\n";
    }
    else if (is_win(f, 'X')) {
        cout << "X" << "\n";
    }
    else if (is_win(f, 'O')) {
        cout << "O" << "\n";
    }
    else {
        cout << "DRAW\n";
    }
}

int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
