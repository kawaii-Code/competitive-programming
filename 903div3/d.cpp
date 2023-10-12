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

template<typename T>
ostream &operator<<(ostream &stream, vector<T> vector) {
    for (int i = 0; i < vector.size(); i++) {
        stream << vector[i] << ", ";
    }
    return stream;
}

void get_divisors(int next, vector<int> &d) {
    if (next == 1) {
        d.push_back(1);
        return;
    }

    for (int i = 1; i < round(sqrt(next)) + 1; i++) {
        if (next % i == 0) {
            d.push_back(i);
            d.push_back(next / i);
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        get_divisors(next, a[i]);
    }

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < a[i].size(); j++) {
            sum += a[i][j];
        }
        sort(a[i].begin(), a[i].end());
        debug(a[i]);
        debug(sum);
    }

    cout << "NO\n";
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
