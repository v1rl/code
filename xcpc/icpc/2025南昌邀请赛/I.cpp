#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

const int mod = 998244353;

vector<int> fact, infact;
void init(int n) {
    fact.resize(n + 1);
    infact.resize(n + 1);
    fact[0] = fact[1] = infact[0] = infact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
        infact[i] = 1ll * (mod - mod / i) * infact[mod % i] % mod;
    }
    for(int i = 2; i <= n; i ++) {
        infact[i] = 1ll * infact[i - 1] * infact[i] % mod;
    }
}

int C(int a, int b) {
    if(a < b) {
        return 0;
    }
    return 1ll * fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> p;
    p.push_back(-1);
    for(int i = 0; i < n; i ++) {
        if(s[i] == '1') {
            p.push_back(i);
        }
    }
    p.push_back(n);

    int ans = 0;
    for(int i = 1; i + k < p.size(); i ++) {
        int len = p[i + k] - p[i - 1] - 1;
        ans = (ans + C(len, k)) % mod;
    }
    for(int i = 1; i + k < p.size() - 1; i ++) {
        int len = p[i + k] - p[i] - 1;
        ans = (ans - C(len, k - 1) + mod) % mod;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    init(100000);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }

    return 0;
}
