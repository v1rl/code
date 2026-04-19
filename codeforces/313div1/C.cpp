#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 1e9 + 7;

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
    int h, w, n;
    cin >> h >> w >> n;
    init(h + w);

    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = {x, y};
    }

    a.push_back({h, w});

    sort(a.begin(), a.end());

    vector<int> f(n + 1);

    auto get = [&](int x, int y) {
        return C(x + y, x);
    };

    for(int i = 0; i <= n; i ++) {
        f[i] = get(a[i][0] - 1, a[i][1] - 1);
        for(int j = 0; j < i; j ++) {
            f[i] = (f[i] - (1ll * f[j] * get(a[i][0] - a[j][0], a[i][1] - a[j][1]) % mod) + mod) % mod;
        }
    }

    cout << f[n] << '\n';
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
