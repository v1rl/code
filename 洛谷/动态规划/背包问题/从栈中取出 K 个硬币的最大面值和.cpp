#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/description/

/*
*/

const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(n);

    vector<vector<int>> v(n), w(n);
    for(int i = 0; i < n; i ++) {
        int m;
        cin >> m;
        a[i].resize(m);
        int s = 0;
        for(int j = 0; j < m; j ++) {
            cin >> a[i][j];
            s += a[i][j];
            v[i].emplace_back(j + 1);
            w[i].emplace_back(s);
        }
    }

    vector<int> f(k + 1);
    for(int i = 0; i < n; i ++) {
        for(int j = k; j >= 0; j --) {
            for(int k = 0; k < v[i].size(); k ++) {
                if(j - v[i][k] >= 0) {
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
                }
            }
        }
    }

    cout << f[k] << '\n';
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
