#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*

*/

void solve() {
    int n, m;
    cin >> n >> m;
    i64 k;
    cin >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector C(n + 1, vector(n + 1, 0ll));
    for(int i = 0; i <= n; i ++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j ++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }

    i64 ans = 0;
    for(int i = 0; i < (1 << n); i ++) {
        int num = __builtin_popcount(i);
        if(num < m) {
            continue;
        }
        i64 lcm = 1;
        bool f = true;
        for(int j = 0; j < n; j ++) {
            if(i >> j & 1) {
                i64 g = __gcd(lcm, a[j]);
                if((i128)lcm / g * a[j] > k) {
                    f = false;
                    break;
                }
                lcm = lcm / g * a[j];
            }
        }
        if(!f) {
            continue;
        }
        ans += ((num - m) % 2 == 0 ? 1 : -1) * C[num][m] * (k / lcm);
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