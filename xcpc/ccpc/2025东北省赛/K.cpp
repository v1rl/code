#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, m;
    cin >> n >> m;
    vector g(n, vector(m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    int ans = n * m;
    vector<int> cpre(m + 1);
    for(int j = 0; j < m; j ++) {
        int res = 1;
        int c = g[0][j];
        for(int i = 1; i < n; i ++) {
            if(g[i][j] == g[i - 1][j]) {
                res ++;
            } else {
                break;
            }
        }
        cpre[c] = max(cpre[c], res);
    }

    for(int i = 1; i <= m; i ++) {
        ans -= cpre[i];
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
