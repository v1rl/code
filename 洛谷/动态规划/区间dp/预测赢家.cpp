#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/predict-the-winner/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }

    /*
    vector f(n, vector(n, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = a[l];
            } else if(len == 2) {
                f[l][r] = max(a[l], a[r]);
            } else {
                f[l][r] = a[l] + min(f[l + 2][r], f[l + 1][r - 1]);
                f[l][r] = max(f[l][r], a[r] + min(f[l + 1][r - 1], f[l][r - 2]));
            }
        }
    }

    cout << (2 * f[0][n - 1] - sum >= 0 )<< '\n';
    */

    vector f(n, vector(n, 0));
    for(int len = 1; len <= n; len ++) {
        for(int l = 0; l + len - 1 < n; l ++) {
            int r = l + len - 1;
            if(len == 1) {
                f[l][r] = a[l];
            } else {
                f[l][r] = max(a[l] - f[l + 1][r], a[r] - f[l][r - 1]);
            }
        }
    }

    cout << (f[0][n - 1] >= 0 ? 1 : 0)  << '\n';
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
