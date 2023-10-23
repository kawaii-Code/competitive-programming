#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define debug(x) std::cout << #x << " = " << x << "\n"

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

template<typename T>
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
void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        a[i] = x[i];
    }

    sort(a.begin(), a.end());

    for (int si = 0; si < n; si++) {
        int s = x[si];
        int asi = 0;
        // wtf
        for (int i = 0; i < asi; i++) {
            if (x[si] == a[i]) {
                asi = i;
            }
        }

        ull sum = 0;
        debug(a);
        debug(s);

        int prev = 0;
        for (int i = 0; i < asi; i++) {
            ull next = (asi - i + 1) * (a[asi] - a[i]);
            debug(next);
            sum += next;
        }

        sum += n;

        prev = a[asi];
        for (int i = si + 1; i < n; i++) {
            ull next = (n - (i - si)) * (a[i] - prev);
            debug(next);
            sum += next;
            prev = a[i];
        }

        cout << sum << "\n";
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
