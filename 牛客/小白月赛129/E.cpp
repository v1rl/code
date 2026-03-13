#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;
const int N = 30;

void solve() {
    int m, c, q;
    cin >> m >> c >> q;

    vector<array<int, 31>> f(m);
    vector<array<i64, 31>> g(m);

    vector<int> a(m);
    for(int i = 0; i < m; i ++) {
        cin >> a[i];
    }

    for(int i = 0; i < m; i ++) {
        f[i][0] = (i + a[i]) % m;
        g[i][0] = (i + a[i]) / m;
    }

    for(int j = 1; j <= N; j ++) {
        for(int i = 0; i < m; i ++) {
            f[i][j] = f[f[i][j - 1]][j - 1];
            g[i][j] = g[i][j - 1] + g[f[i][j - 1]][j - 1];
        }
    }

    while(q --) {
        int x;
        cin >> x;
        if(x > c) {
            cout << "No" << '\n';
            continue;
        }

        i64 l = 0, r = 1 << N;

        int p = x / m;
        x %= m;

        auto check = [&](i64 mid) -> i64 {
            i64 res = p;
            int cur = x;
            for(int i = N; i >= 0; i --) {
                if(mid >> i & 1) {
                    res += g[cur][i];
                    cur = f[cur][i];
                }
            }
            return 1ll * res * m + cur;
        };

        while(l < r) {
            i64 mid = l + r >> 1;
            if(check(mid) >= c) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if(check(l) == c) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
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