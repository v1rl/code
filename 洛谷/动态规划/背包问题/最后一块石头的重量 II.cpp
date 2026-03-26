#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/last-stone-weight-ii/description/

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

    int ans = sum;
    sum /= 2;

    vector<int> f(sum + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = sum; j >= a[i]; j --) {
            f[j] = max(f[j], f[j - a[i]] + a[i]);
        }
    }

    cout << ans - 2 * f[sum] << '\n';
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
