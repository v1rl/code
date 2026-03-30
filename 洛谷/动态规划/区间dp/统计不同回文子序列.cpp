#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/count-different-palindromic-subsequences/description/

/*
f[左l][右r]的子序列个数
*/

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> pos(26, -1);
    vector<int> lst(n);
    vector<int> ne(n);
    for(int i = 0; i < n; i ++) {
        int ch = s[i] - 'a';
        lst[i] = pos[ch];
        pos[ch] = i;
    }

    pos.assign(26, n);
    for(int i = n - 1; i >= 0; i --) {
        int ch = s[i] - 'a';
        ne[i] = pos[ch];
        pos[ch] = i;
    }

    vector f(n, vector(n, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = 1;
            } else {
                if(s[l] != s[r]) {
                    f[l][r] = ((f[l + 1][r] + f[l][r - 1] - f[l + 1][r - 1]) % mod + mod) % mod;
                } else {
                    int x = ne[l];
                    int y = lst[r];
                    if(x > y) {
                        f[l][r] = f[l + 1][r - 1] * 2 + 2;
                        f[l][r] %= mod;
                    } else if(x == y) {
                        f[l][r] = f[l + 1][r - 1] * 2 + 1;
                        f[l][r] %= mod;
                    } else {
                        f[l][r] = ((f[l + 1][r - 1] * 2 - f[x + 1][y - 1]) % mod + mod) % mod;
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