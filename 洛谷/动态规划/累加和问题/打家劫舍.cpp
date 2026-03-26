#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/house-robber/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;

    int ans = -1e9;
    vector<int> f(n);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        f[i] = x;
        if(i > 0) {
            f[i] = max(f[i - 1], f[i]);
        }
        if(i > 1) {
            f[i] = max(f[i - 2] + x, f[i]);
        }
        ans = max(ans, f[i]);
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
