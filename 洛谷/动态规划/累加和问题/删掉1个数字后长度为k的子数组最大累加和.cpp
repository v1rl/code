#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/description/

/*
删掉1个数字后长度为k的子数组最大累加和
给定一个数组nums，求必须删除一个数字后的新数组中
长度为k的子数组最大累加和，删除哪个数字随意
*/

const int inf = 1e9;

int solve1(vector<int> &a, int k) {
    int n = a.size() - 1;
    int ans = -inf;
    deque<int> q;
    int sum = 0;
    for(int l = 1, r = 1; r <= n; r ++) {
        sum += a[r];
        if(q.size() && r - q.front() + 1 > k + 1) {
            q.pop_front();
        }
        while(q.size() && a[q.back()] >= a[r]) {
            q.pop_back();
        }
        q.push_back(r);
        if(r - l + 1 == k + 1) {
            ans = max(ans, sum - a[q.front()]);
            sum -= a[l];
            l ++;
        }
    }
    return ans;
}

int solve2(vector<int> &a, int k) {
    int n = a.size() - 1;
    int ans = -inf;
    int sum = 0;

    for(int l = 1, r = 1; r <= n; r ++) {
        sum += a[r];
        if(r - l + 1 == k + 1) {
            for(int j = l; j <= r; j ++) {
                ans = max(ans, sum - a[j]);
            }
            sum -= a[l];
            l ++;
        }
    }
    return ans;
}

void checker() {
    mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(int i = 0; i < 100; i ++) {
        int n = rng() % 50 + 2;
        int k = rng() % (n - 1) + 1;

        vector<int> a(n + 1);
        for(int j = 1; j <= n; j ++) {
            a[j] = rng() % 1000 - 500;
        }
        int ans1 = solve1(a, k), ans2 = solve2(a, k);
        if(ans1 != ans2) {
            cout << "WA ON TEST" << ' ' << i + 1 << '\n';
            cout << n << ' ' << k << '\n';
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