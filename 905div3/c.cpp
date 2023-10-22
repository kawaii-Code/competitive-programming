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

    int result = 10;
    bool found1 = false;
    bool found2 = false;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        if (next % k == 0) {
            result = 0;
        }
        if (k - (next % k) < result) {
            result = k - (next % k);
        }

        if (k == 4) {
            if (found1 && next % 2 == 1) {
                result = result > 2 ? 2 : result;
            }
            if (found1 && next % 2 == 0) {
                result = result > 1 ? 1 : result;
            }
            if (found2 && next % 2 == 1) {
                result = result > 1 ? 1 : result;
            }
            if (found2 && next % 2 == 0) {
                result = 0;
            }
            if (next % 2 == 1) {
                found1 = true;
            }
            if (next % 2 == 0) {
                found2 = true;
            }
        }
    }

    cout << result << "\n";
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
