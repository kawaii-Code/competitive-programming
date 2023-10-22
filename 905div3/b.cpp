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

template <typename T>
ostream &operator <<(ostream &stream, const vector<T> &vector) {
    if (vector.size() == 0) {
        stream << "[]";
        return stream;
    }

    stream << "[";
    for (int i = 0; i < vector.size() - 1; i++) {
        stream << vector[i] << ", ";
    }
    stream << vector[vector.size() - 1] << "]";
    return stream;
}

#define debug(x) std::cout << #x << " = " << x << "\n"
#define debug2(x, y) std:: cout << #x << " = " << x << " " << #y << " = " << y << "\n";
#define debug3(x, y, z) std:: cout << #x << " = " << x << " " << #y << " = " << y << " " << #z << " = " << z << "\n";

void solve() {
    int n, k;
    cin >> n >> k;
    string s;

    char counts[256] = {};
    for (int i = 0; i < n; i++) {
        char next;
        cin >> next;
        counts[next]++;
    }

    int odds = 0;
    for (int i = 0; i < 256; ++i) {
        odds += counts[i] % 2;
    }

    if (n - k == 1) {
        cout << "YES\n";
        return;
    }

    if (k > odds) {
        int diff = k - odds;
        if (diff % 2 == 1 && (n - k) % 2 == 1) {
            cout << "YES\n";
        } else if (diff % 2 == 0 && (n - k) % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    else if (k == odds) {
        cout << "YES\n";
    }
    else {
        int diff = odds - k;
        if (diff == 1) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
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
