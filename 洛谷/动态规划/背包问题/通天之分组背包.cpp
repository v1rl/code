#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://www.luogu.com.cn/problem/P1757

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<vector<int>> v(10001), w(10001);
    for(int i = 1; i <= n; i ++) {
        int cv, cw, b;
        cin >> cv >> cw >> b;
        v[b].emplace_back(cv);
        w[b].emplace_back(cw);
    }

    vector<int> f(m + 1);
    for(int i = 0; i <= 10000; i ++) {
        for(int j = m; j >= 0; j --) {
            for(int k = 0; k < v[i].size(); k ++) {
                if(j - v[i][k] >= 0) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[m] << '\n';
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
