#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
typedef pair<int, int> PII;
const int inf = 1e9;
const int mod = 1e9 + 7;

/*

*/

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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> bk(n + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        bk[x] ++;
    }

    int cnt = 0;
    i64 res = 1;
    for(int i = 1; i <= n; i ++) {
        if(!bk[i]) {
            continue;
        }
        if(bk[i] % i != 0) {
            cout << 0 << '\n';
            return;
        }

        int k = bk[i] / i;
        cnt += k;

        res = res * fact[bk[i]] % mod * qmi(infact[i], k) % mod * infact[k] % mod;
    }
    if(cnt > m) {
        cout << 0 << '\n';
        return;
    }

    for(int i = 0; i < cnt; i ++) {
        res = res * (m - i) % mod;
    }

    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(200000);
    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}