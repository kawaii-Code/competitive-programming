#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;

    ll sum = 0;
    int operations = 0;
    bool last_negative = false;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        
        if (next > 0) {
            sum += next;
            last_negative = false;
        } else if (next < 0) {
            sum += -next;
            if (!last_negative) {
                last_negative = true;
                operations++;
            }
        }
    }

    cout << sum << " " << operations << "\n";
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
