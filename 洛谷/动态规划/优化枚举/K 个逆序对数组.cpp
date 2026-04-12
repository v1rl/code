#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/k-inverse-pairs-array/description/

/*
f[i][j] 表示前i个数中有j个逆序对的数量
*/

const int mod = 1e9 + 7;

void solve() {
    int n, c;
    cin >> n >> c;

    vector f(n, vector(c + 1, 0));
    f[0][0] = 1;
    /*
    for(int i = 1; i < n; i ++) {
        for(int j = 0; j <= c; j ++) {
            for(int k = j; k >= max(j - i, 0); k --) {
                f[i][j] = (f[i][j] + f[i - 1][k]) % mod;
            }
        }
    }
    cout << f[n - 1][c] << '\n';
    */

    /*
    for(int i = 1; i < n; i ++) {
        vector<int> pre(c + 2);
        f[i][0] = pre[1] = f[i - 1][0];
        for(int j = 1; j <= c; j ++) {
            pre[j + 1] = (pre[j] + f[i - 1][j]) % mod;
            f[i][j] = ((pre[j + 1] - pre[max(0, j - i)]) % mod + mod) % mod;
        }
    }
    cout << f[n - 1][c] << '\n';
    */

    for(int i = 1; i < n; i ++) {
        f[i][0] = f[i - 1][0];
        for(int j = 1; j <= c; j ++) {
            f[i][j] = (f[i][j - 1] + f[i - 1][j]) % mod;
            if(j > i) {
                f[i][j] = ((f[i][j] - f[i - 1][j - i - 1]) % mod + mod) % mod;
            }
        }
    }
    cout << f[n - 1][c] << '\n';
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
