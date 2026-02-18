#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

const int inf = 2e9;

/*
*/

vector<int> minp, primes, mu;
void sieve(int n) {
    minp.assign(n + 1, 0);
    mu.assign(n + 1, 0);

    mu[1] = 1;
    for(int i = 2; i <= n; i ++) {
        if(!minp[i]) {
            mu[i] = -1;
            minp[i] = i;
            primes.emplace_back(i);
        }
        for(auto p : primes) {
            if(p * i > n) break;
            minp[p * i] = p;
            if(i % p == 0) break;
            mu[i * p] = -mu[i];
        }
    }

    for(int i = 1; i <= n; i ++) {
        mu[i] += mu[i - 1];
    }
}

void solve() {
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    
    auto work = [&](int n, int m) -> i64 {
        i64 res = 0;
        for(int l = 1, r; l <= min(n, m); l = r + 1) {
            r = min(n / (n / l), m / (m / l));
            res += 1ll * (mu[min({n, m, r})] - mu[l - 1]) * (m / l) * (n / l);
        }
        return res;
    };

    i64 ans = work(b / k, d / k) - work(b / k, (c - 1) / k) - work((a - 1) / k, d / k) + work((a - 1) / k, (c - 1) / k);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    sieve(50000);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}