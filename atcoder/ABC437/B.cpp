#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector g(n, vector(m, 0));
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }

    set<int> S;
    for(int i = 0; i < t; i ++) {
        int x;
        cin >> x;
        S.insert(x);
    }

    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int num = 0;
        for(int j = 0; j < m; j ++) {
            if(S.count(g[i][j])) {
                num ++;
            }
        }
        ans = max(ans, num);
    }

    cout << ans << "\n";
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
