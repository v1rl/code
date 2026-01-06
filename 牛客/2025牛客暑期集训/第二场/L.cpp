#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
const int mod = 998244353;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    iota(p.begin(), p.end(), 0);
    auto find = [&](auto && self, int x) -> int{
        if(x != p[x]) p[x] = self(self, p[x]);
        return p[x];
    };
    vector<int> siz(n + 1, 1);
    for(int i = 1; i <= n; i ++) {
        int x = i;
        int y;
        cin >> y;
        x = find(find, x), y = find(find, y);
        if(x == y) continue;
        p[x] = y;
        siz[y] += siz[x];
    }

    int num1 = 0;
    int inv_2 = qmi(2, mod - 2);

    vector<int> vis(n + 1);
    i64 res = 1;
    for(int i = 1; i <= n; i ++) {
        int x = find(find, i);
        if(vis[x]) continue;
        vis[x] = true;
        int num = siz[x];
        if(num & 1) {
            num1 ++;
        } else if(num > 2) {
            res *= 2;
            res %= mod;
        }
    }
    if(num1 > 2) {
        cout << 0 << '\n';
    } else if(num1 == 0) {
        i64 ans = 0;
        vector<int> vis(n + 1);
        bool f = false;

        for(int i = 1; i <= n; i ++) {
            int x = find(find, i);
            if(vis[x]) continue;
            vis[x] = true;
            int num = siz[x];
            if(num == 2) {
                ans += res % mod;
            } else {
                ans += (1ll * num * num / 4) % mod * res % mod * inv_2 % mod;
            }
            ans %= mod;
        }
        cout << ans << '\n';
    } else {
        i64 ans = 1;
        vector<int> vis(n + 1);
        for(int i = 1; i <= n; i ++) {
            int x = find(find, i);
            if(vis[x]) continue;
            vis[x] = true;
            int num = siz[x];
            if(num & 1) {
                ans *= num;
                ans %= mod;
            } else if(num > 2) {
                ans *= 2;
                ans %= mod;
            }
        }
        cout << ans % mod << '\n';
    }

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}