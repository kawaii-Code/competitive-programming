#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Range {
    int left;
    int right;
    int needOnes;
    int count;
};

int compare(Range left, Range right) {
    if (left.left == right.left) {
        return left.right < right.right;
    }
    return left.left < right.left;
}

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Range> ranges(m);
    for (int i = 0; i < m; i++) {
        int left, right;
        cin >> left >> right;

        int length = right - left + 1;
        int needOnes = length / 2 + 1;
        Range range = {left - 1, right - 1, needOnes, 0};
        ranges[i] = range;
    }

    sort(ranges.begin(), ranges.end(), compare);

    int min = 2147483647;
    bool solution = false;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int next;
        cin >> next;

        if (solution) {
            continue;
        }
        next--;

        int left = 0;
        int right = m - 1;
        int middle;
        bool found = false;
        while (left <= right) {
            middle = (left + right) / 2;

            if (ranges[middle].right < next) {
                left = middle + 1;
                std::cout << "l\n";
            } else if (ranges[middle].left > next) {
                right = middle - 1;
                std::cout << "r\n";
            } else {
                found = true;
                break;
            }
        }

        if (!found) {
            continue;
        }

        int ri = middle;
        while (ri >= 0 && ranges[ri].left <= next) {
            ranges[ri].count++;
            if (ranges[ri].count == ranges[ri].needOnes) {
                min = i + 1;
                std::cout << min << "\n";
                solution = true;
                break;
            }
            ri--;
        }

        ri = middle + 1;
        while (ri < m && ranges[ri].right >= next) {
            ranges[ri].count++;
            if (ranges[ri].count == ranges[ri].needOnes) {
                min = i + 1;
                std::cout << min << "\n";
                solution = true;
                break;
            }
            ri++;
        }
    }

    std::cout << -1 << "\n";
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
