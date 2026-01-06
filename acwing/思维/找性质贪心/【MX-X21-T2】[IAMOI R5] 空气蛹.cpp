#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

// https://www.luogu.com.cn/problem/P14057

#define int long long

/*
找到水量最小的两个杯子，倒在一起，得到一个空杯子
注意到：利用空杯子进行排序
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    bool f = false;
    for(int i = 0; i < n - 1; i ++) {
        if(a[i + 1] < a[i]) {
            f = true;
            break;
        }
    }
    if(!f) {
        cout << accumulate(a.begin(), a.end(), 0ll) << '\n';
        return;
    }

    sort(a.begin(), a.end());
    int ans = min(a[0] + a[1], m); 
    for(int i = 2; i < n; i ++) {
        ans += a[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}