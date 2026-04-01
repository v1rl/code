#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/matchsticks-to-square/description/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int sum = accumulate(a.begin(), a.end(), 0);
    if(sum % 4 != 0) {
        cout << 0 << '\n';
        return;
    }

    int tar = sum / 4;
    vector<int> f(1 << n, -1);
    auto dfs = [&](auto &&self, int s, int len, int u) -> bool {
        if(u == 4) {
            return true;
        }
        if(f[s] != -1) {
            return f[s];
        }
        bool ok = false;
        for(int i = 0; i < n; i ++) {
            if(~s >> i & 1) {
                int nlen = len + a[i];
                if(nlen < tar) {
                    ok |= self(self, s | (1 << i), nlen, u);
                } else if(nlen == tar) {
                    ok |= self(self, s | (1 << i), 0, u + 1);
                }
                if(ok) {
                    break;
                }
            }
        }
        return f[s] = ok;
    };
    cout << dfs(dfs, 0, 0, 0) << '\n';
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
