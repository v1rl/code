#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long
typedef pair<int, int> PII;
const int inf = 1e9;
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
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    int na = 0, nb = 0;
    for(int i = 0; i < n; i ++) {
        if(s[i] == 'A') {
            na ++;
        } else if(s[i] == 'B') {
            nb ++;
        }
    }

    vector<int> qmi2(na + 1);
    qmi2[0] = 1;
    for(int i = 1; i <= na; i ++) {
        qmi2[i] = qmi2[i - 1] * 2 % mod;
    }

    vector<int> Ca(na + 1), Cb(nb + 1);
    vector<int> sum(nb + 1);
    Ca[0] = 1, Cb[0] = 1;
    sum[0] = 1;
    for(int i = 1, j = na; i <= na; i ++, j --) {
        Ca[i] = Ca[i - 1] * j % mod * qmi(i, mod - 2) % mod;
    }
    for(int i = 1, j = nb; i <= nb; i ++, j --) {
        Cb[i] = Cb[i - 1] * j % mod * qmi(i, mod - 2) % mod;
        sum[i] = (sum[i - 1] + Cb[i]) % mod;
    }

    int ans = 0;
    for(int i = 0; i <= min(m, na); i ++) {
        if(m - i < 0) {
            continue;
        }
        ans += qmi2[i] * Ca[i] % mod * sum[min(m - i, nb)] % mod;
        ans %= mod;
        // cout << ans << '\n';
    }
    cout << ans << '\n';
}


signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
}