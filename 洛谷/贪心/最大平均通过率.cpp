#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

typedef tuple<double, int, int> tp;

// https://leetcode.cn/problems/maximum-average-pass-ratio/description/

void solve() {
    int n;
    cin >> n;
    priority_queue<tp> heap;
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        heap.push({1.0 * (x + 1) / (y + 1) - 1.0 * x / y, x + 1, y + 1});
    }

    int m;
    cin >> m;
    while(m --) {
        auto [v, x, y] = heap.top();
        heap.pop();

        heap.push({1.0 * (x + 1) / (y + 1) - 1.0 * x / y, x + 1, y + 1});
    }

    double ans = 0;
    while(heap.size()) {
        auto [v, x, y] = heap.top();
        heap.pop();

        ans += 1.0 * (x - 1) / (y - 1);
    }

    cout << fixed << setprecision(8);
    cout << ans / n << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}