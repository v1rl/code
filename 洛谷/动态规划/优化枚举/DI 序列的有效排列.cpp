#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/valid-permutations-for-di-sequence/description/

/*
f[i][j]前i个数中，比第i个选择数小的，还没被选取的数还有j个的有效排列数量
*/

const int mod = 1e9 + 7;

void solve() {
    string s;
    cin >> s;
    int n = s.size();

    s = '#' + s;    
    vector f(n + 1, vector(n + 1, 0));
    for(int i = 0; i <= n; i ++) {
        f[0][i] = 1;
    }

    /*
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= n + 1 - i; j ++) {
            if(f[i - 1][j] == 0) {
                continue;
            }
            int x = n + 1 - i - j;
            if(s[i] == 'D') {
                for(int k = 0; k < j; k ++) {
                    f[i][k] = (f[i][k] + f[i - 1][j]) % mod;
                }
            } else {
                for(int k = 0; k < x; k ++) {
                    f[i][j + k] = (f[i][j + k] + f[i - 1][j]) % mod;
                }
            }
        }
    }
    */

    for(int i = 1; i <= n; i ++) {
        if(s[i] == 'D') {
            for(int j = n - i; j >= 0; j --) {
                f[i][j] = (f[i][j + 1] + f[i - 1][j + 1]) % mod;
            }
        } else {
            f[i][0] = f[i - 1][0];
            for(int j = 1; j <= n - i; j ++) {
                f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;
            }
        }
    }

    cout << f[n][0] << '\n';
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
