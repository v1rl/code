#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*
f[前i个][最后一个值为j^2][总和为k]的最小代价
*/

const int inf = 1e9;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }

    int S = pre[n];
    int T = sqrt(S);

    /*
    vector f(n + 1, vector(T + 1, vector(S + 1, inf)));
    f[0][0][0] = 0;

    for(int i = 1; i <= n; i ++) {

        vector mn(T + 1, vector(S + 1, inf));
        for(int k = 0; k <= S; k ++) {
            mn[0][k] = f[i - 1][0][k];
            for(int j = 1; j <= T; j ++) {
                mn[j][k] = min(mn[j - 1][k], f[i - 1][j][k]);
            }
        }

        for(int j = 0; j <= T; j ++) {
            for(int k = j * j; k <= S; k ++) {
                int pk = k - j * j;
                if(mn[j][pk] != inf) {
                    f[i][j][k] = mn[j][pk] + abs(pre[i] - k);
                }
            }
        }
    }

    int ans = inf;
    for(int j = 0; j <= T; j ++) {
        ans = min(ans, f[n][j][S]);
    }

    cout << (ans == inf ? -1 : ans) << '\n';
    */

    vector f(T + 1, vector(S + 1, inf));
    f[0][0] = 0;

    for(int i = 1; i <= n; i ++) {

        vector mn(T + 1, vector(S + 1, inf));
        for(int k = 0; k <= S; k ++) {
            mn[0][k] = f[0][k];
            for(int j = 1; j <= T; j ++) {
                mn[j][k] = min(mn[j - 1][k], f[j][k]);
            }
        }

        for(int j = 0; j <= T; j ++) {
            for(int k = j * j; k <= S; k ++) {
                int pk = k - j * j;
                if(mn[j][pk] != inf) {
                    f[j][k] = mn[j][pk] + abs(pre[i] - k);
                }
            }
        }
    }

    int ans = inf;
    for(int j = 0; j <= T; j ++) {
        ans = min(ans, f[j][S]);
    }

    cout << (ans == inf ? -1 : ans) << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
