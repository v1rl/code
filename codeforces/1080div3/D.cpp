#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u32 = unsigned;
typedef pair<i64, i64> PII;

/*
*/

void solve() {
    int n;
    cin >> n;
    vector<i64> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    vector<i64> f(n + 1);
    for(int i = 2; i <= n - 1; i ++) {
        f[i] = (a[i + 1] - 2 * a[i] + a[i - 1]) / 2;
    }

    i64 res = a[1];
    for(int i = 2; i <= n - 1; i ++) {
        res -= f[i] * (i - 1);
    }

    f[n] = res / (n - 1);

    res = a[2];
    for(int i = 2; i <= n; i ++) {
        res -= f[i] * (i - 2);
    }

    f[1] = res;

    for(int i = 1; i <= n; i ++) {
        cout << f[i] << ' ';
    }
    cout << '\n';
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
