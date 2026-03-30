#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimum-cost-to-merge-stones/description/

/*
f[左l][右r]合并的最低花销
*/

const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n + 1);
    vector<int> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    if((n - 1) % (k - 1) != 0) {
        cout << -1 << '\n';
        return;
    }

    vector f(n + 1, vector(n + 1, inf));
    for(int len = 1; len <= n; len ++) {
        for(int l = 1; l + len - 1 <= n; l ++) {
            int r = l + len - 1;
            if(len < k) {
                f[l][r] = 0;
            } else {
                for(int i = l; i < r; i += k - 1) {
                    f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r]);
                }
                if((r - l) % (k - 1) == 0) {
                    f[l][r] += pre[r] - pre[l - 1];
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