#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
using i128 = __int128;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }

    int m = a[n - 1];
    vector<int> f(m + 1);
    vector<int> bk(m + 1);
    f[0] = 0;

    for(int i = 1, j = 0; i <= m; i ++) {
        if(j < n && a[j] <= i) {
            j ++;
        }
        f[i] = f[i - a[j - 1]] + 1;
        bk[f[i]] ++;
    }

    for(int i = 1; i <= m; i ++) {
        bk[i] += bk[i - 1];
    }

    while(q --) {
        int x;
        cin >> x;
        x = min(x, m);
        cout << bk[x] << ' ';
    }
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
