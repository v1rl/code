#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-circular-subarray/description/

/*
*/

const int inf = 1e9;

void solve() {
    /*
    // 正难则反的动态规划
    int n;
    cin >> n;
    int pmx = -inf, pmn = inf;
    int mx = -inf, mn = inf;
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        sum += x;
        pmx = max(pmx + x, x);
        pmn = min(pmn + x, x);
        mx = max(mx, pmx);
        mn = min(mn, pmn);
    }
    if(sum != mn) {
        mx = max(mx, sum - mn);
    }
    cout << mx << '\n';
    */

    // 前缀和+单调队列
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pre(n * 2 + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    for(int i = n + 1; i <= 2 * n; i ++) {
        pre[i] = pre[i - 1] + a[i - n];
    }

    deque<int> q;
    int ans = -inf;
    q.push_back(0);
    for(int i = 1; i <= 2 * n; i ++) {
        if(q.size() && i - q.front() > n) {
            q.pop_front();
        }

        ans = max(ans, pre[i] - pre[q.front()]);

        while(q.size() && pre[q.back()] >= pre[i]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    cout << ans << '\n';
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
