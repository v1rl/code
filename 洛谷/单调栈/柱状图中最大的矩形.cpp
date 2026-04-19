#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://leetcode.cn/problems/largest-rectangle-in-histogram/description/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<int> l(n, -1), r(n, n);
    vector<int> stk;
    for(int i = 0; i < n; i ++) {
        while(!stk.empty() && a[stk.back()] >= a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            l[i] = stk.back();
        }
        stk.push_back(i);
    }
    stk.clear();
    for(int i = n - 1; i >= 0; i --) {
        while(!stk.empty() && a[stk.back()] >= a[i]) {
            stk.pop_back();
        }
        if(!stk.empty()) {
            r[i] = stk.back();
        }
        stk.push_back(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        ans = max(ans, a[i] * (r[i] - l[i] - 1));
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
