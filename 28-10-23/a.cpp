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

#define debug(x) std::cout << #x << " = " << x << std::endl

void solve() {
    int n;
    cin >> n;

    int *colors = new int[n];
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        debug(next);
        while (next != 0)
        {
            graph[i].push_back(next - 1);
            cin >> next;
        }
    }

    stack<int> s;
    int currentColor = 1;
    s.push(1);
    while (s.empty()) {
        int current = s.top();
        s.pop();

        for (int node : graph[current]) {
            if (colors[node] != 0) {
                debug(colors[node]);
                continue;
            }

            colors[node] = currentColor;
            if (currentColor == 1) {
                currentColor = 2;
            } else {
                currentColor = 1;
            }
            s.push(node);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc = 1;
    std::cout << "hello" << "\n";
    debug(tc);
    std::cout << "hi" << "\n";
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
