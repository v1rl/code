#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

/*

*/

void solve() {
    int n, m;
    i64 k;
    cin >> n >> m >> k;
    vector<i64> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    
    vector<i64> dp(1 << n);
    for(int mask = 0; mask <= (1 << n); mask ++) {
        i64 lcm = 1;
        bool f = true;
        for(int j = 0; j < n; j ++) {
            if(mask >> j & 1) {
                i64 g = __gcd(lcm, a[j]);
                if((i128)lcm / g * a[j] > k) {
                    f = false;
                    break;
                }
                lcm = lcm / g * a[j];
            }
        }
        if(f) {
            dp[mask] = k / lcm;
        }
    }

    for(int i = 0; i < n; i ++) {
        for(int mask = 0; mask < (1 << n); mask ++) {
            if(!(mask >> i & 1)) {
                dp[mask] -= dp[mask | (1 << i)];
            }
        }
    }

    i64 ans = 0;
    for(int mask = 0; mask < (1 << n); mask ++) {
        if(__builtin_popcount(mask) == m) {
            ans += dp[mask];
        }
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