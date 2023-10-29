#include <iostream>
#include <functional>
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

struct Med {
    short d;
    short h;
    short s;
};

struct Node {
    short s;
    short d;
};

ostream &operator <<(ostream &s, Node node) {
    s << node.s << " " << node.d << "\n";
    return s;
}

short *cache;

void solve() {
    for (int i = 0; i < 1024; i++) {
        cache[i] = 0;
    }

    short n, m;
    cin >> n >> m;
    short ss = 0;
    for (int i = 0; i < n; i++) {
        char bit;
        cin >> bit;
        bit -= '0';
        ss = (ss << 1) | bit;
    }

    vector<Med> v(m);
    for (int i = 0; i < m; i++) {
        short d;
        cin >> d;

        short h = 0;
        for (int f = 0; f < n; f++) {
            char bit;
            cin >> bit;
            bit -= '0';
            h = (h << 1) | bit;
        }

        short s = 0;
        for (int f = 0; f < n; f++) {
            char bit;
            cin >> bit;
            bit -= '0';
            s = (s << 1) | bit;
        }

        Med med;
        med.d = d;
        med.h = h;
        med.s = s;
        v[i] = med;
    }

    int result = -1;
    queue<Node> q;
    Node initial;
    initial.s = ss;
    initial.d = 0;
    q.push(initial);
    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        if (cache[current.s] != 0 && cache[current.s] < current.d) {
            continue;
        }
        cache[current.s] = current.d;

        if (current.s == 0) {
            if (result == -1 || result > current.d) {
                result = current.d;
                continue;
            }
        }

        for (int i = 0; i < m; i++) {
            Med med = v[i];
            Node next;
            next.s = (current.s & ~med.h) | med.s;
            next.d = current.d + med.d;
            if (cache[next.s] != 0 && cache[next.s] < next.d) {
                continue;
            } else {
                q.emplace(next);
            }
        }
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cache = new short[1024];

    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}
