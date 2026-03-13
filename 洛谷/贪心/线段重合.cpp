#include <bits/stdc++.h>
using namespace std;

// https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37

void solve() {
    // 贪心 + 堆
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    priority_queue<int, vector<int>, greater<int>> heap;
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        auto [l, r] = a[i];
        while(heap.size() && heap.top() <= l) {
            heap.pop();
        }
        heap.push(r);
        ans = max(ans, (int)heap.size());
    }
    cout << ans << '\n';

    /*
    // 差分 (+ 离散化)
    int n;
    cin >> n;
    vector<int> a(100010);
    for(int i = 0; i < n; i ++) {
        int l, r;
        cin >> l >> r;
        a[l] ++;
        a[r] --;
    }
    int ans = 0;
    for(int i = 1; i <= 100000; i ++) {
        a[i] += a[i - 1];
        ans = max(ans, a[i]);
    }
    cout << ans << '\n';
    */
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