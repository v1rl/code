#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/burst-balloons/description/

/*
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    a[0] = 1, a[n + 1] = 1;

    vector f(n + 1, vector(n + 1, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = a[l - 1] * a[l] * a[l + 1];
            } else {
                f[l][r] = a[l - 1] * a[l] * a[r + 1] + f[l + 1][r];
                f[l][r] = max(f[l][r], a[l - 1] * a[r] * a[r + 1] + f[l][r - 1]);
                for(int k = l + 1; k <= r - 1; k ++) {
                    f[l][r] = max(f[l][r], a[k] * a[l - 1] * a[r + 1] + f[l][k - 1] + f[k + 1][r]);
                }
            }
        }
    }

    cout << f[1][n] << '\n';
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
