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
    int a, b, d;
    cin >> a >> b >> d;
    
    a /= d, b /= d;
    int n = min(a, b);
    i64 ans = 0;
    for(int l = 1, r; l <= n; l = r + 1) {
        r = min(a / (a / l), b / (b / l));
        ans += 1ll * (mu[min(r, n)] - mu[l - 1]) * (a / l) * (b / l);
    }
    
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