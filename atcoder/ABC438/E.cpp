#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<array<int, 31>> p(n + 1);
    vector<array<i64, 31>> f(n + 1);
    for(int i = 1; i <= n; i ++) {
        p[i][0] = a[i];
        f[i][0] = i;
    }
    for(int i = 1; i <= 30; i ++) {
        for(int j = 1; j <= n; j ++) {
            p[j][i] = p[p[j][i - 1]][i - 1];
            f[j][i] = f[j][i - 1] + f[p[j][i - 1]][i - 1];
        }
    }

    while(m --) {
        int t, x;
        cin >> t >> x;
        i64 ans = 0;
        for(int i = 0; i <= 30; i ++) {
            if(t >> i & 1) {
                ans += f[x][i];
                x = p[x][i];
            }
        }
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
