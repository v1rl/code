#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

/*
*/

const int inf = 1e9;

void solve() {
    /*
    // 前后缀分解，预处理前后缀最值
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    vector<int> s(n - k + 1);
    int sum = 0;
    for(int l = 0, r = 0; r < n; r ++) {
        sum += a[r];
        if(r - l + 1 == k) {
            s[l] = sum;
            sum -= a[l];
            l ++;
        }
    }

    vector<int> pre(n), suf(n);
    pre[k - 1] = 0;
    for(int i = k; i < n; i ++) {
        pre[i] = pre[i - 1];
        if(s[i - k + 1] > s[pre[i - 1]]) {
            pre[i] = i - k + 1;
        }
    }
    suf[n - k] = n - k;
    for(int i = n - k - 1; i >= 0; i --) {
        suf[i] = suf[i + 1];
        if(s[i] >= s[suf[i + 1]]) {
            suf[i] = i;
        }
    }

    int ans = 0;
    int p1, p2, p3;
    for(int i = k; i <= n - k - k; i ++) {
        int cur = s[pre[i - 1]] + s[i] + s[suf[i + k]];
        if(cur > ans) {
            ans = cur;
            p1 = pre[i - 1];
            p2 = i;
            p3 = suf[i + k];
        }
    }
    cout << ans << '\n';
    cout << p1 << ' ' << p2 << ' ' << p3 << '\n';
    */

    // 动态规划
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> s(n + 1);
    int sum = 0;
    for(int l = 1, r = 1; r <= n; r ++) {
        sum += a[r];
        if(r - l + 1 == k) {
            s[r] = sum;
            sum -= a[l];
            l ++;
        }
    }

    vector<array<int, 4>> f(n + 1);
    int mx = 0;
    for(int i = k; i <= n; i ++) {
        for(int j = 1; j <= 3; j ++) {
            f[i][j] = max(f[i - 1][j], f[i - k][j - 1] + s[i]);
        }
    }

    cout << f[n][3] << '\n';

    int i = n, j = 3;
    vector<int> ans;
    while(j > 0) {
        if(f[i][j] == f[i - 1][j]) {
            i --;
        } else {
            ans.emplace_back(i - k);
            i -= k;
            j --;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto c : ans) {
        cout << c << ' ';
    }
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
