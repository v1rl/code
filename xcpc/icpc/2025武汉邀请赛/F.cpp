#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;
const i64 inf = 1e18;

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
    i64 n, m;
    cin >> n >> m;
    vector<array<i64, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        i64 x, c;
        cin >> c >> x;
        a[i] = {x, c};
    }

    sort(a.begin(), a.end(), greater());

    i64 ans, rem;
    int lst;
    {
        auto [x, c] = a[0];
        i64 num = (c + m - 1) / m;
        ans = num % mod * qmi(2, x) % mod;
        rem = num * m - c;
        lst = x;
    }

    for(int i = 1; i < n; i ++) {
        auto [x, c] = a[i];
        int d = lst - x;
        if(rem > 0) {
            if(d > 55 || inf / rem < (1ll << d)) {
                cout << ans << '\n';
                return;
            }
            rem = rem * (1ll << d);
        }

        if(c <= rem) {
            rem -= c;
        } else {
            i64 mor = c - rem;
            i64 num = (mor + m - 1) / m;
            ans = (ans + num % mod * qmi(2, x) % mod) % mod;
            rem = num * m - mor;
        }

        lst = x;
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
