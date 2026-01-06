#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1e9;
// https://codeforces.com/contest/2149/problem/E

/*
关键词：子段，贪心，双指针，区间计数，区间并

找到k个不同的连续子段，其长度在[l, r]之间
本题答案维护的是子段
暴力O(n^2)可以得到答案，我们考虑优化
注意到：对于固定的l，答案约束下的r的取值区间为 [第k个不同数的首位, 第k个不同数的末位] 和 [i + l - 1, i + r - 1] 的交集
并且，在l单调右移的过程中，第k个不同数的首位以及末尾也是单调右移的
于是，我们同时维护第k个不同数的首位以及末位这两个值
*/

void solve() {
    int n, k, l, r;
    cin >> n >> k >> l >> r;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> val = a;
    sort(val.begin(), val.end());
    for(int i = 0; i < n; i ++) {
        a[i] = lower_bound(val.begin(), val.end(), a[i]) - val.begin();
    }

    vector<int> st1(n), st2(n);
    int j1 = 0, j2 = 0;
    int c1 = 0, c2 = 0;
    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        // 需要注意，j - 1才是第一个不符合if中条件的点
        while(j1 < n && c1 < k) {
            c1 += !st1[a[j1]] ++;
            j1 ++;
        }
        while(j2 < n && c2 <= k) {
            c2 += !st2[a[j2]] ++;
            j2 ++;
        }
        // 需要注意，因为我们无法得知当j跑到最后时j - 1到底是不是我们想要的，所欲我们需要对最后做一个特判(或者设置一个哨兵节点)
        if(j1 == n && c1 < k) j1 ++;
        if(j2 == n && c2 <= k) j2 ++;
        ans += max(min(j2 - 2, i + r - 1) - max(j1 - 1, i + l - 1) + 1, 0);
        c1 -= !-- st1[a[i]];
        c2 -= !-- st2[a[i]];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}