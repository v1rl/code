#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/description/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n + 1);
    for(int i = 0; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = {i - x, i + x};
    }

    sort(a.begin(), a.end());
    int cur = 0;
    int cnt = 0;
    priority_queue<int> heap;
    int i = 0;
    while(cur < n) {
        while(i <= n && a[i][0] <= cur) {
            heap.push(a[i][1]);
            i ++;
        }
        if(heap.empty()) {
            cout << -1 << '\n';
            return;
        }
        cur = heap.top();
        heap.pop();
        cnt ++;
    }
    cout << cnt << '\n';
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