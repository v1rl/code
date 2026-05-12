#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

const int mod = 998244353;
const int inf = 1e9;

vector<int> fact;
void init(int n) {
    fact.resize(n + 1);
    fact[0] = fact[1] = 1;
    for(int i = 2; i <= n; i ++) {
        fact[i] = 1ll * fact[i - 1] * i % mod;
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int mn = inf;
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
        mn = min(mn, b[i]);
    }
    
    i64 ans = 1ll * fact[mn - 1] * fact[n - mn + 1] % mod;
    cout << ans << '\n';
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