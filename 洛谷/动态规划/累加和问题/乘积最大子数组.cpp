#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-product-subarray/description/

/*
*/

const i64 inf = 3e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    i64 pmx = a[0], pmn = a[0];
    i64 mx = a[0];
    for(int i = 1; i < n; i ++) {
        i64 t = pmx;
        pmx = max<i64>({a[i], pmx * a[i], pmn * a[i]});
        pmn = min<i64>({a[i], t * a[i], pmn * a[i]});
        mx = max(mx, pmx);
    }   
    cout << mx << '\n';
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
