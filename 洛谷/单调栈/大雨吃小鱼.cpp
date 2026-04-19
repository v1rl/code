#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

// https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    vector<array<int, 2>> stk;
    int ans = 0;
    for(int i = n - 1; i >= 0; i --) {
        int res = 0;
        while(!stk.empty() && a[stk.back()[0]] < a[i]) {
            res ++;
            res = max(res, stk.back()[1]);
            stk.pop_back();
        }
        ans = max(ans, res);
        stk.push_back({i, res});
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
