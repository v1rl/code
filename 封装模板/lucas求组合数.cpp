#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
模数必须为素数
*/

int mod;
vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);

    fact[0] = infact[0] = fact[1] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(i64 a, i64 b) {
    if(a < b) {
        return 0;
    }
    if(a < mod) {
        return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
    }
    return 1ll * C(a / mod, b / mod) * C(a % mod, b % mod) % mod;
}

void solve() {
    cin >> mod;
    init(mod);

    int t;
    cin >> t;
    while(t --) {
        i64 a, b;
        cin >> a >> b;
        cout << C(a, b) << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}