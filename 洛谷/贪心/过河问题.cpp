#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P1809

/*
运送两个人到对岸的两种情况
a[0] * 2 + a[n - 2] + a[n - 1]
a[0] + a[1] * 2 + a[n - 1];
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());


    i64 ans = 0;
    while(n > 3) {
        ans += min(a[0] * 2 + a[n - 2] + a[n - 1], a[0] + a[1] * 2 + a[n - 1]);
        n -= 2;
    }

    if(n == 1) {
        ans += a[0];
    } else if(n == 2) {
        ans += a[1];
    } else if(n == 3) {
        ans += a[0] + a[1] + a[2];
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}