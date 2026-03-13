#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/description/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    sort(a.begin(), a.end());

    priority_queue<int, vector<int>, greater<int>> heap;
    int i = 0;
    int d = 1;
    int ans = 0;
    while(i < n || heap.size()) {
        if(heap.empty()) {
            d = a[i][0];
        }
        while(i < n && a[i][0] == d) {
            heap.push(a[i][1]);
            i ++;
        }
        while(heap.size() && heap.top() < d) {
            heap.pop();
        }
        if(!heap.empty()) {
            heap.pop();
            ans ++;
        }
        d ++;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}