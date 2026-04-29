#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int inf = 1e9;
const int mod = 1e9 + 7;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }

    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        if(i - k >= 0) {
            a[i] = a[i - k] + b[i];
        } else {
            a[i] = b[i];
        }
    }

    vector<i64> c(n + 2);
    for(int i = 1; i <= n; i ++) {
        c[i] = a[i] - a[i - 1];
    }

    vector<int> fact(n + 1), infact(n + 1);
    fact[0] = fact[1] = infact[0] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i] * infact[i - 1] % mod; 
    }

    int ans = 1;
    for(int i = 1; i <= k; i ++) {
        vector<i64> res;
        for(int j = i; j <= n - k + 1; j += k) {
            res.emplace_back(c[j]);
        }

        sort(res.begin(), res.end());
        int cnt = 1;
        int cur = fact[res.size()];
        for(int j = 1; j < res.size(); j ++) {
            if(res[j] == res[j - 1]) {
                cnt ++;
            } else {
                cur = 1ll * cur * infact[cnt] % mod;
                cnt = 1;
            }
        }
        cur = 1ll * cur * infact[cnt] % mod;
        ans = 1ll * ans * cur % mod;
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
