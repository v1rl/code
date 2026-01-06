#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
数据范围只到150，考虑搜索剪枝
总数的阶乘/相同数个数的阶乘 * 2
*/

const i64 inf = 1e18;
const int mod = 1e9 + 7;

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
    int n, m;
    cin >> n >> m;
    vector<int> st(n + 1);
    i64 ans = 0;

    vector<int> a(n + 1);
    vector<int> inva(n + 1);
    a[1] = inva[1] = 1;
    for(int i = 2; i <= n; i ++) {
        a[i] = 1ll * a[i - 1] * i % mod;
        inva[i] = qmi(a[i], mod - 2);
    }

    auto dfs = [&](auto &&self, int p, int lth, int res) {
        if(p != 0) {
            int t = lth % p;
            int ps = t * (t - 1) / 2;
            int cmx = p * (p - 1) / 2 * (lth / p) + ps;
            if(cmx < res) {
                return;
            }
            if(p == 1) {
                st[p] = lth;
                self(self, p - 1, 0, 0);
                return;
            }
            if(p == 2) {
                st[2] = res;
                st[1] = lth - res * 2;
                self(self, p - 2, 0, 0);
                return;
            }
        }

        if(p == 0) {
            if(!(res == 0 && lth == 0)) {
                return;
            }
            int sum = 0;
            i64 res = 1;
            for(int i = 1; i <= n; i ++) {
                if(st[i] > 0) {
                    sum += st[i];
                    res *= inva[st[i]];
                    res %= mod;
                }
            }
            res = 1ll * res * a[sum] % mod * 2 % mod;
            ans = (ans + res) % mod;
            return;
        }

        int base = p * (p - 1) / 2;
        for(int i = 0; i <= n; i ++) {
            int cres = res - i * base;
            int clth = lth - i * p;
            // cout << cres << ' ' << clth << '\n';
            if(cres < 0 || clth < 0) {
                break;
            }
            st[p] = i;
            self(self, p - 1, clth, cres);
        }
    };

    dfs(dfs, n, n, m);
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