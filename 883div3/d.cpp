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
#include <iomanip>

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

#define debug(x) std::cout << #x << " = " << x << "\n"

void solve() {
    int n, d, h;
    cin >> n >> d >> h;

    double result = 0.0;
    int prevHeight = -1;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;

        result += (double)h * (double)d / 2.0;
        if (prevHeight != -1 && next - prevHeight < h) {
            int heightDiff = h - (next - prevHeight);
            double lesser = (double)heightDiff * ((double)d / 2.0) * ((double)heightDiff / (double)h);
            result -= lesser;
        }
        prevHeight = next;
    }
    cout << fixed << setprecision(15) << result << "\n";
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
