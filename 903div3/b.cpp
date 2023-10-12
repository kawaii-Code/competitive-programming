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

void solve() {
    int a, b, c;
    vector<int> arr(27);
    cin >> a >> b >> c;
    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    int count = 3;
    if (a == b && b == c) {

    }

    for (int i = 0; i < 3; i++) {
        int mx = 0;
        int mxi = 0;
        int mn = 1'000'000'001;
        bool ok = true;
        for (int i = 0; i < count; i++) {
            if (arr[i] == -1) {
                continue;
            }
            if (arr[i] > mx) {
                mx = arr[i];
                mxi = i;
            }
            if (arr[i] < mn) {
                mn = arr[i];
            }

            if (i == 0) {
                continue;
            }
            int j = i - 1;
            while (j > 0 && arr[j] == -1) {
                j--;
            }
            if (arr[j] != -1 && arr[i] != arr[j]) {
                ok = false;
            }
        }

        if (ok) {
            cout << "YES\n";
            return;
        }

        arr[count] = mn;
        arr[count+1] = mx - mn;
        arr[mxi] = -1;
        count += 2;
    }

    bool ok = true;
    for (int i = 0; i < count; i++) {
        if (i == 0 || arr[i] == -1) {
            continue;
        }

        int j = i - 1;
        while (j > 0 && arr[j] == -1) {
            j--;
        }
        if (arr[j] != -1 && arr[i] != arr[j]) {
            ok = false;
        }
    }

    if (ok) {
        cout << "YES\n";
        return;
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
