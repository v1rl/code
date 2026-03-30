#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/remove-boxes/description/

/*
f[左l][右r][左侧存在k个与l相等的字符]的最大得分
*/

const int mod = 19650827;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector f(n, vector(n, vector(n, 0)));

    auto dfs = [&](auto &&self, int l, int r, int k) {
        if(l > r) {
            return 0;
        }
        if(f[l][r][k]) {
            return f[l][r][k];
        }
        int x = l + 1;
        while(x < r + 1 && a[x] == a[x - 1]) {
            x ++;
        }
        int num = k + x - l;
        int ans = self(self, x, r, 0) + num * num;
        for(int y = x + 1; y < r + 1; y ++) {
            if(a[y] == a[l] && a[y] != a[y - 1]) {
                ans = max(ans, self(self, x, y - 1, 0) + self(self, y, r, num));
            }
        }
        return f[l][r][k] = ans;
    };

    cout << dfs(dfs, 0, n - 1, 0) << '\n';
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