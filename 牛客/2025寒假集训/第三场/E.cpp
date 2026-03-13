#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    i64 t = 1ll * n * (n - 1) / 2;
    if(k < t) {
        cout << "NO" << '\n';
        return;
    }
    k -= t;

    vector<int> e(n);
    iota(e.begin(), e.end(), 0);

    for(int i = n - 1; i >= 1; i --) {
        int t = min<i64>({k, m - (n - 1 - i) - e[i], 1ll * (i - 2) * (i - 1) / 2});
        e[i] += t;
        k -= t;
    }

    if(k) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    for(int i = 1; i <= n - 1; i ++) {
        cout << i << ' ' << i + 1 << ' ' << e[i] << '\n';
    }

    vector<int> vis(m + 1);
    for(auto x : e) {
        vis[x] = 1;
    }

    int v = 1;
    while(v <= m && vis[v]) {
        v ++;
    }

    for(int y = 3; y <= n; y ++) {
        for(int x = 1; x <= y - 2 && v <= m; x ++) {
            cout << x << ' ' << y << ' ' << v << '\n';
            vis[v] = true;
            while(v <= m && vis[v]) {
                v ++;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}