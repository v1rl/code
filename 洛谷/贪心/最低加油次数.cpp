#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/minimum-number-of-refueling-stops/description/

void solve() {
    int tar, m;
    cin >> tar >> m;
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());

    priority_queue<int> heap;
    int cur = m;
    int cnt = 0;
    int i = 0;
    while(cur < tar) {
        while(i < n && a[i][0] <= cur) {
            heap.push(a[i][1]);
            i ++;
        }
        if(heap.empty()) {
            cout << -1 << '\n';
            return;
        }
        cur += heap.top();
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