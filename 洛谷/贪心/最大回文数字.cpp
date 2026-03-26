#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://leetcode.cn/problems/largest-palindromic-number/description/

void solve() {
    string s;
    cin >> s;
    vector<int> num(10);
    for(auto c : s) {
        num[c - '0'] ++;
    }

    int cnt = 0;
    bool mid = false;
    for(int i = 1; i < 10; i ++) {
        if(num[i] & 1) {
            mid = true;
            cnt += num[i] - 1;
        } else {
            cnt += num[i];
        }
    }

    if(cnt > 1) {
        if(num[0] & 1) {
            mid = true;
            cnt += num[0] - 1;
        } else {
            cnt += num[0];
        }
    }

    cnt += mid;
    // cout << cnt << '\n';

    vector<int> ans(cnt);
    int cur = 0;

    for(int i = 1; i < 10; i ++) {
        if(num[i] & 1) {
            ans[cnt / 2] = i;
        }
        for(int j = 0; j < num[i] / 2; j ++) {
            ans[cur] = ans[cnt - 1 - cur] = i;
            cur ++;
        }
    }
    if(cur) {
        if(num[0] & 1) {
            ans[cnt / 2] = 0;
        }
        for(int j = 0; j < num[0] / 2; j ++) {
            ans[cur] = ans[cnt - 1 - cur] = 0;
            cur ++;
        }
    }

    for(auto c : ans) {
        cout << c;
    }
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