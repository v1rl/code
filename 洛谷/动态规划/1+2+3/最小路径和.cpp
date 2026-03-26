#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/minimum-path-sum/

const int mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;

    vector g(n, vector(m, 0));

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(i == 0 && j == 0) {
                continue;
            } else if(i == 0) {
                g[i][j] += g[i][j - 1];
            } else if(j == 0) {
                g[i][j] += g[i - 1][j];
            } else {
                g[i][j] += min(g[i - 1][j], g[i][j - 1]);
            }
        }
    }
    
    cout << g[n - 1][m - 1] << '\n';
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
