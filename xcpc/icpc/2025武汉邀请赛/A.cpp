#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

const int mod = 998244353;


void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<int> L(n + 1, -1), R(n + 1, 1e9 + 10);
    while(q --) {
        int x, l, r;
        cin >> x >> l >> r;
        L[x] = max(L[x], l);
        R[x] = min(R[x], r);
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(L[i] > R[i]) {
            cout << -1 << '\n';
            return;
        }
        if((L[i] <= a[i] && a[i] <= R[i]) || L[i] == -1) {
            continue;
        } 
        ans += min(abs(L[i] - a[i]), abs(a[i] - R[i])); 
    }
    cout << ans << '\n';
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
