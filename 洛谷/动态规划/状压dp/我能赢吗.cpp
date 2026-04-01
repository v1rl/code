#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/can-i-win/description/

void solve() {
    int n, m;
    cin >> n >> m;

    if(n * (n + 1) / 2 < m) {
        cout << 0 << '\n';
        return;
    }    

    if(m == 0) {
        cout << 1 << '\n';
        return;
    }

    vector<int> f(1 << n, -1);
    auto dfs = [&](auto && self, int res, int s) -> bool {
        if(res <= 0) {
            return false;
        }
        if(f[s] != -1) {
            return f[s];
        }            

        bool ok = false;
        for(int i = 0; i < n; i ++) {
            if(~s >> i & 1) {
                ok |= !self(self, res - i - 1, s | (1 << i));
            }
        }
        return f[s] = ok;
    };

    cout << dfs(dfs, m, 0) << '\n';
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
