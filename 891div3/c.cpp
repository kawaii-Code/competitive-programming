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

    int nn = (n*(n-1))/2;
    vector<int> a(nn);
    for (int i = 0; i < nn; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ai = 0;
    for (int i = 1; i < n; i++) {
        cout << a[ai] << " ";
        ai += n - i;
    }
    cout << 1000*1000*1000 << " ";
    cout << "\n";
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
