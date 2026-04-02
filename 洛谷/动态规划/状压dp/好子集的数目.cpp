#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

// https://leetcode.cn/problems/the-number-of-good-subsets/description/

const int mod = 1e9 + 7;

i64 qmi(i64 a, i64 b) {
    i64 res = 1;
    while(b) {
        if(b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve() {
    vector<int> id(31);
    vector<int> primes;
    vector<vector<int>> g(31);
    int m = 30;
    for(int i = 2; i <= m; i ++) {
        int x = i;
        set<int> S;
        bool okO = true;
        bool okP = true;

        for(int j = 2; j * j <= x; j ++) {
            if(x % j == 0) {
                okP = false;
                int cnt = 0;
                while(x % j == 0) {
                    cnt ++;
                    x /= j;
                }
                if(cnt > 1) {
                    okO = false;
                }
                S.insert(j);
            }
        }

        if(x > 1) {
            S.insert(x);
        }

        if(okP) {
            id[i] = primes.size();
            primes.emplace_back(i);
        }
        if(okO) {
            for(auto c : S) {
                g[i].emplace_back(id[c]);
            }            
        }
    }

    int n;
    cin >> n;
    vector<int> bk(31);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        bk[x] ++;
    }

    n = primes.size();
    vector f(31, vector(1 << n, 0));
    f[1][0] = 1;
    for(int i = 2; i <= 30; i ++) {
        for(int mask = 0; mask < (1 << n); mask ++) {
            if(f[i - 1][mask] == 0) {
                continue;
            }
            f[i][mask] = (f[i][mask] + f[i - 1][mask]) % mod;

            if(g[i].size() == 0) {
                continue;
            }

            int sub = 0;
            for(auto c : g[i]) {
                sub ^= 1 << c;
            }
            if((mask & sub) == 0) {
                f[i][mask ^ sub] = (f[i][mask ^ sub] + 1ll * f[i - 1][mask] * bk[i]) % mod;
            }
        }
    }

    i64 ans = qmi(2, bk[1]);
    int res = 0;
    for(int mask = 1; mask < (1 << n); mask ++) {
        res = (res + f[30][mask]) % mod;
    }
    ans = ans * res % mod;
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
