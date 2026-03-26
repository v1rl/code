#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-subarray/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    int ans = -1e9, pre = 0;
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        pre = max(pre + x, x);
        ans = max(ans, pre);
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
