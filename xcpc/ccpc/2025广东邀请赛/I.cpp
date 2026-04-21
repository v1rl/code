#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int mod = 998244353;

i64 get(auto &a, int mask) {
    i64 res = 0;
    if(mask & 1) {
        res |= a[0];
    }
    if(mask & 2) {
        res |= a[1] << 20;
    }
    if(mask & 4) {
        res |= a[2] << 40;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<array<i64, 3>> a(n);
    unordered_map<i64, int> cnt[8];
    for(int i = 0; i < n; i ++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        for(int mask = 1; mask < 8; mask ++) {
            cnt[mask][get(a[i], mask)] ++;
        }
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        vector<int> g(8);
        for(int mask = 1; mask < 8; mask ++) {
            g[mask] = cnt[mask][get(a[i], mask)] - 1;
        }
        vector<int> f = g;

        for(int bit = 0; bit < 3; bit ++) {
            for(int mask = 0; mask < (1 << 3); mask ++) {
                if((mask & (1 << bit)) == 0) {
                    f[mask] -= f[mask | (1 << bit)];
                }
            }
        }

        int sum = 0;
        for(int i = 1; i < 8; i ++) {
            sum += f[i];
        }

        i64 res = 1ll * sum * (sum - 1) / 2;
        res -= 1ll * f[1] * (f[1] - 1) / 2;
        res -= 1ll * f[2] * (f[2] - 1) / 2;
        res -= 1ll * f[4] * (f[4] - 1) / 2;

        ans += res;
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
