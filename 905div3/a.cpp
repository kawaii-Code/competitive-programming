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
    int current = 1;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        char digit;
        cin >> digit;
        int digitint = digit - '0';
        if (digitint == 0) {
            digitint = 10;
        }

        int diff = digitint - current;
        result += diff < 0 ? -diff : diff;

        current = digitint;
        result++;
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
