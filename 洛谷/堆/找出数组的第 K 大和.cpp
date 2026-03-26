#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/find-the-k-sum-of-an-array/description/

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    i64 sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] >= 0) {
            sum += a[i];
        } else {
            a[i] = -a[i];
        }

    }

    sort(a.begin(), a.end());
    i64 ans = 0;
    k --;

    priority_queue<array<i64, 2>, vector<array<i64, 2>>, greater<array<i64, 2>>> heap;
    heap.push({a[0], 0});

    while(k --) {
        auto [v, r] = heap.top();
        heap.pop();

        ans = v;

        if(r != n - 1) {
            heap.push({v + a[r + 1], r + 1});
            heap.push({v - a[r] + a[r + 1], r + 1});
        }
    }

    cout << sum - ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
