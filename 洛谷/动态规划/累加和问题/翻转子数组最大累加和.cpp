#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

/*
可以翻转1次的情况下子数组最大累加和
给定一个数组nums，
现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
比如翻转[1,2,3,4,5,6]的[2~4]范围，得到的是[1,2,5,4,3,6]
返回必须随意翻转1次之后，子数组的最大累加和
*/

const int inf = 1e9;

int solve1(vector<int> &a) {
    int n = a.size() - 1;

    vector<int> pre(n + 1), suf(n + 2);
    vector<int> smx(n + 2, 0);
    for(int i = 1; i <= n; i ++) {
        pre[i] = max(pre[i - 1] + a[i], a[i]);
    }
    for(int i = n; i >= 1; i --) {
        suf[i] = max(suf[i + 1] + a[i], a[i]);
        smx[i] = max(suf[i], smx[i + 1]);
    }

    int ans = -inf;
    for(int i = 1; i <= n; i ++) {
        ans = max(ans, pre[i] + smx[i + 1]);
    }
    
    return ans;
}

int solve2(vector<int> &a) {
    int n = a.size() - 1;

    int ans = -inf;

    for(int l = 1; l <= n; l ++) {
        for(int r = l; r <= n; r ++) {

            for(int i = l, j = r; i < j; i ++, j --) {
                swap(a[i], a[j]);
            }

            int pre = 0, mx = -inf;
            for(int i = 1; i <= n; i ++) {
                pre = max(pre + a[i], a[i]);
                mx = max(mx, pre);
            }

            ans = max(ans, mx);

            for(int i = l, j = r; i < j; i ++, j --) {
                swap(a[i], a[j]);
            }
        }
    }

    return ans;
}

void checker() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < 100; i ++) {
        int n = rng() % 50 + 1;
        vector<int> a(n + 1);
        for(int j = 1; j <= n; j ++) {
            a[j] = rng() % 1000 - 500;
        }
        int ans1 = solve1(a), ans2 = solve2(a);
        if(ans1 != ans2) {
            cout << "WA ON TEST" << ' ' << i + 1 << '\n';
            for(int j = 1; j <= n; j ++) {
                cout << a[j] << " \n"[j == n];
            }
            cout << ans1 << ' ' << ans2 << '\n';
            return;
        }
    }
    cout << "Accepted!";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while(t --) {
        checker();
    }

    return 0;
}