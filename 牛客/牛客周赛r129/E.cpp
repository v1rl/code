#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
*/

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
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}


void solve() {
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        cout << 1ll * C(n, i) * qmi(2, n - i) % mod * qmi(2, i - 1) % mod << ' ';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(200000);
    int t = 1;
    // cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}