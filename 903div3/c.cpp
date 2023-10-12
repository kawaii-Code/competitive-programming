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
    stream << "\n";
    return stream;
}
void solve() {
    int n;
    cin >> n;

    vector<vector<char>> a(n);
    vector<vector<char>> b(n);
    for (int i = 0; i < n; i++) {
        a[i].resize(n);
        b[i].resize(n);
        for (int j = 0; j < n; j++) {
            char next;
            cin >> next;
            a[i][j] = next;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            b[j][n-i-1] = a[i][j];
        }
    }

    ull result = 0;
    for (int t = 0; t < 27; t++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int e1 = a[i][j];
                int e2 = b[i][j];

                ull diff = e1 > e2 ? e1 - e2 : e2 - e1;

                if (e1 < e2) {
                    a[i][j] += diff;
                    b[j][n-i-1] += diff;
                    result += diff;
                } else if (e2 > e1) {
                    a[n-j-1][i] += diff;
                    b[i][j] += diff;
                    result += diff;
                }
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
