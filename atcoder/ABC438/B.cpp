#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/


void solve() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    int ans = 1e9;
    for(int i = 0; i < n - m + 1; i ++) {
        int res = 0;
        for(int j = 0; j < m; j ++) {
            int d = s[i + j] - t[j];
            if(d < 0) {
                d += 10;
            }
            res += d;
        }
        ans = min(res, ans);
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
