#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/tJau2o/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v, w;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        int t = 2 * y - x;
        if(t <= 0) {
            m += -t;
            ans += z;
        } else {
            v.emplace_back(t);
            w.emplace_back(z);
        }
    }

    n = v.size();
    vector<int> f(m + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = m; j >= v[i]; j --) {
            f[j] = max(f[j], f[j - v[i]] + w[i]);
        }
    }

    cout << ans + f[m] << '\n';
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
