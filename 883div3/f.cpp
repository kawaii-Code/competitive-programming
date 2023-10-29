#include <stdio.h>
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

int n;
vector<int> counts(10);
vector<int> previousCounts(10);
vector<int> current;

void idle() {
    cout << "- 0" << endl << endl;
    cout.flush();
    for (int i = 0; i < 10; i++) {
        previousCounts[i] = counts[i];
        counts[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        current[i] = next;
        counts[next]++;
    }
}

pair<int, int> diff() {
    int lessIndex = 0;
    int moreIndex = 0;
    for (int i = 1; i <= 9; i++) {
        if (counts[i] < previousCounts[i]) {
            lessIndex = i;
        } else if (counts[i] > previousCounts[i]) {
            moreIndex = i;
        }
    }
    return make_pair(lessIndex, moreIndex);
}

void stage3(int a) {
    for (int i = 0; i < 10; i++) {
        previousCounts[i] = 0;
        counts[i] = 0;
    }
    int found = -1;
    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        if (next != a) {
            found = i;
        }
        current[i] = next;
        counts[next]++;
    }

    if (found != - 1) {
        cout << "! " << found + 1 << endl << endl;
        cout.flush();
        return;
    }

    idle();
    auto d = diff();
    for (int i = 0; i < n; i++) {
        if (current[i] == d.second) {
            cout << "! " << i + 1 << endl << endl;
            cout.flush();
            return;
        }
    }
}

void stage2(pair<int, int> d) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (current[i] == d.second) {
            count++;
        }
    }

    cout << "- " << n - count << " ";
    for (int i = 0; i < n; i++) {
        if (current[i] != d.second) {
            cout << i + 1 << " ";
        }
    }
    cout << endl << endl;
    cout.flush();

    n = count;
    stage3(d.second);
}

void solve() {
    cin >> n;
    current.resize(n);
    for (int i = 0; i < n; i++) {
        current[i] = 0;
    }
    for (int i = 0; i < 10; i++) {
        counts[i] = 0;
        previousCounts[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int next;
        cin >> next;
        counts[next]++;
    }

    idle();
    auto d = diff();

    if (d.first != 0) {
        stage2(d);
    } else {
        idle();
        d = diff();
        stage2(d);
    }
}

int main() {
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
        cout << endl;
        cout.flush();
    }
}
