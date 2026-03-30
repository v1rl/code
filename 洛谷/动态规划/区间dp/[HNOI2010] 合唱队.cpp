#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P3205

/*
*/

const int mod = 19650827;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    if(n == 1) {
        cout << 1 << '\n';
        return;
    }

    vector f(n, vector(n, (array<int, 2>){0, 0}));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 2) {
                if(a[l] < a[r]) {
                    f[l][r][0] = 1;
                    f[l][r][1] = 1;
                }
            } else {
                if(a[l] < a[l + 1]) {
                    f[l][r][0] += f[l + 1][r][0];
                }
                if(a[l] < a[r]) {
                    f[l][r][0] += f[l + 1][r][1];
                }
                if(a[r] > a[l]) {
                    f[l][r][1] += f[l][r - 1][0];
                }
                if(a[r] > a[r - 1]) {
                    f[l][r][1] += f[l][r - 1][1];
                }

                f[l][r][0] %= mod;
                f[l][r][1] %= mod;
            }
        }
    }

    cout << (f[0][n - 1][0] + f[0][n - 1][1]) % mod << '\n';
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