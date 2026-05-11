#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

vector<int> primes, minp;
void sieve(int n) {
    minp.assign(n + 1, 0);
    for(int i = 2; i <= n; i ++) {
        if(!minp[i]) {
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes) {
            if(p * i > n) {
                break;
            }
            minp[p * i] = p;
            if(minp[i] == p) {
                break;
            }
        }
    }
}

const int inf = 1e9;
const i64 INF = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    sieve(m);

    vector<int> mn(m + 1, inf);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        vector<array<int, 2>> ps;

        int temp = x;
        while(minp[x] != 0) {
            int p = minp[x];
            int cnt = 0;
            while(x % p == 0) {
                x /= p;
                cnt ++;
            }
            ps.push_back({p, cnt});
        }
        x = temp;

        i64 ans = INF;
        auto dfs = [&](auto &&self, int u, int res) -> void {
            if(u == ps.size()) {
                if(mn[res] != inf) {
                    ans = min(ans, 1ll * x * mn[res] / res);
                }
                mn[res] = min(mn[res], x);
                return;
            }

            auto [p, cnt] = ps[u];
            int cur = 1;
            self(self, u + 1, res);
            for(int i = 1; i <= cnt; i ++) {
                cur *= p;
                self(self, u + 1, res * cur);
            }
        };

        dfs(dfs, 0, 1);
        if(i > 1) {
            cout << ans << ' ';
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
