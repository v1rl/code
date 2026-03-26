#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

typedef tuple<double, int, int> tp;

// https://leetcode.cn/problems/minimum-cost-to-hire-k-workers/description/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return (double)x[1] / x[0] < (double)y[1] / y[0];
        });

    int k;
    cin >> k;
    priority_queue<int> heap;
    int sum = 0;
    double mx = 0;
    double ans = 0;
    for(int i = 0; i < n; i ++) {
        auto [x, y] = a[i];
        if(i < k) {
            sum += x;
            heap.push(x);
            if(i == k - 1) {
                mx = (double)y / x;
                ans = mx * sum;
            }
        } else {
            sum -= heap.top();
            heap.pop();
            sum += x;
            heap.push(x);
            mx = double(y) / x;
            ans = min(ans, mx * sum);
        }
    }

    cout << fixed << setprecision(8);
    cout << ans << '\n';
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