#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-length-of-pair-chain/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }

    /*
    // 比较与插入数据不同的LIS
    sort(a.begin(), a.end());
    vector<int> ed;
    for(int i = 0; i < n; i ++) {
        auto it = lower_bound(ed.begin(), ed.end(), a[i][0]);
        if(it == ed.end()) {
            ed.push_back(a[i][1]);
        } else {
            int pos = it - ed.begin();
            ed[pos] = min(ed[pos], a[i][1]);
        }
    }

    cout << ed.size() << '\n';
    */

    // 贪心
    sort(a.begin(), a.end(), 
        [&](auto x, auto y) {
            return x[1] < y[1];
        });

    int lst = -1e9;
    int ans = 0;
    for(auto [l, r] : a) {
        if(l > lst) {
            ans ++;
            lst = r;
        }
    }

    cout << ans << '\n';
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
