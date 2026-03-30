#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/description/

/*
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector f(n, vector(n, inf));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1 || len == 2) {
                f[l][r] = 0;
            } else {
                for(int k = l + 1; k <= r - 1; k ++) {
                    f[l][r] = min(f[l][r], a[l] * a[k] * a[r] + f[l][k] + f[k][r]);
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
