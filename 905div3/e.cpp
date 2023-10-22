#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
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
    int n;
    cin >> n;

    vector<double> a(n);
    for (int i = 0 ;i < n; i++) {
        int next;
        cin >> next;
        a[i] = log2(next);
    }

    int result = 0;
    int previ = 0;
    for (int i = 0; i < n - 1; i++) {
        double i1;
        double i2;
        double frac1;
        double frac2;

        frac1 = modf(a[i], &i1);
        frac2 = modf(a[i + 1], &i2);
        if (i == 0) {
            previ = (int)i1;
        }

        if (previ > i2 || (previ == i2 && frac1 > frac2)) {
            int diff = previ - i2;
            if (frac1 > frac2) {
                diff++;
            }

            previ = i2;
            previ += diff;
            result += diff;
        } else {
            previ = i2;
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
