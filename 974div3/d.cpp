#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define debug(x) std::cout << #x << " = " << x << std::endl

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
    int n,d,k;
    cin >> n >> d >> k;
    d -= 1;

    int m = n - d;
    vector<int> dp(m, 0);
    for (ll i = 0; i < k; i++) {
        int left, right;
        cin >> left >> right;
        left -= 1;
        right -= 1;

        int lb = max(left - d, 0);
        int rb = min(right, m - 1);
        for (int j = lb; j <= rb; j++) {
            dp[j] += 1;
        }
    }

    int min = 1000000;
    int max = -1;
    for (int i = 0; i < m; i++) {
        if (dp[i] < min) {
            min = dp[i];
        }
        if (dp[i] > max) {
            max = dp[i];
        }
    }

    for (int i = 0; i < m; i++) {
        if (dp[i] == max) {
            cout << i + 1 << " ";
            break;
        }
    }

    for (int i = 0; i < m; i++) {
        if (dp[i] == min) {
            cout << i + 1 << "\n";
            break;
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
