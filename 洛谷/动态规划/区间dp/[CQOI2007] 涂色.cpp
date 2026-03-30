#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P4170

/*
*/

const int inf = 1e9;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector f(n, vector(n, inf));

    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = 1;
            } else if(len == 2) {
                f[l][r] = 2;
                if(s[l] == s[r]) {
                    f[l][r] --;
                }
            } else {
                if(s[l] == s[r]) {
                    f[l][r] = min(f[l + 1][r], f[l][r - 1]);
                } else {
                    for(int k = l; k <= r - 1; k ++) {
                        f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
                    }
                }
            }
        }
    }
    cout << f[0][n - 1] << '\n';
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
