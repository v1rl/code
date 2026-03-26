#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/longest-valid-parentheses/

const int mod = 1e9 + 7;
const i64 inf = 1e18;


void solve() {
    /*
    // dp做法
    string s;
    cin >> s;
    vector<int> f(s.size());
    f[0] = 0;
    for(int i = 1; i < s.size(); i ++) {
        if(s[i] == '(') {
            f[i] = 0;
        } else {
            int res = f[i - 1];
            int lpos = i - f[i - 1] - 1;
            if(lpos >= 0 && s[lpos] == '(') {
                res += 2;
                if(lpos - 1 >= 0) {
                    res += f[lpos - 1];
                }
            } else {
                res = 0;
            }
            f[i] = res;
        }
    }

    cout << *max_element(f.begin(), f.end()) << '\n';
    */

    // 贪心做法
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    int l = 0, r = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == '(') {
            l ++;
        } else {
            r ++;
        }
        if(l == r) {
            ans = max(ans, l + r);
        } else if(l < r) {
            l = r = 0;
        }
    }
    l = r = 0;
    for(int i = n; i >= 0; i --) {
        if(s[i] == '(') {
            l ++;
        } else {
            r ++;
        }
        if(l == r) {
            ans = max(ans, l + r);
        } else if(l > r) {
            l = r = 0;
        }
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
