#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
(j-L+1)*(R-j+1)
-j^2+j(L+R)-(L-1)(R+1)
*/

typedef pair<i64, int> PII;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<array<i64, 3>> pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> pre[i][0];
        pre[i][1] = pre[i][0] * i;
        pre[i][2] = pre[i][1] * i;

        pre[i][0] += pre[i - 1][0];
        pre[i][1] += pre[i - 1][1];
        pre[i][2] += pre[i - 1][2];
    }

    while(q --) {
        int l, r;
        cin >> l >> r;
        i64 ans = -(pre[r][2] - pre[l - 1][2]);
        ans += (l + r) * (pre[r][1] - pre[l - 1][1]);
        ans -= (pre[r][0] - pre[l - 1][0]) * (l - 1) * (r + 1);
        cout << ans << '\n';
    }
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