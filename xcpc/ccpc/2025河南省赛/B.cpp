#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;
const int mod = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    vector<int> inv(n + 1);
    inv[1] = 1;
    for(int i = 2; i <= n; i ++) {
        inv[i] = 1ll * (mod - mod / i) * inv[mod % i] % mod;
    }

    vector dp(2, vector(n + 1, vector<int>(1, 0)));
    int p = 0;
    vector<int> cnt(n + 1);
    int emp = 1;
    int cur = 0;

    for(int i = 0; i < n; i ++) {
        if(a[i] != -1) {
            p ++;
            cnt[a[i]] ++;
            dp[cur][a[i]].emplace_back(0);
            dp[cur ^ 1][a[i]].emplace_back(0);
        } else {
            int sum = emp;
            emp = 0;
            for(int j = 0; j <= n; j ++) {
                if(cnt[j] == 0) {
                    continue;
                }

                dp[cur][j][1] = 1ll * sum * cnt[j] % mod * inv[p] % mod;

                for(int k = 2; k <= cnt[j]; k ++) {
                    if(cnt[j] - k + 1 > 0) {
                        dp[cur][j][k] = 1ll * dp[cur ^ 1][j][k - 1] * (cnt[j] - k + 1) % mod * inv[p] % mod;
                    }
                }

                for(int k = 0; k <= cnt[j]; k ++) {
                    sum = (sum + dp[cur ^ 1][j][k]) % mod;
                }
            }
            cur ^= 1;
            p --;
        }
    }

    int ans = 0;
    for(int j = 0; j <= n; j ++) {
        for(int k = 0; k <= cnt[j]; k ++) {
            ans = (ans + dp[cur ^ 1][j][k]) % mod;
        }
    }
    cout << ans << '\n';
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
