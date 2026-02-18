#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

const int mod = 998244353;
const int inf = 1e9 + 7;

void solve() {
    i64 a[3];
    cin >> a[0] >> a[1] >> a[2];
    i64 s = a[0] + a[1] + a[2];
    int p = s / 3;
    int q = p + 1;

    bool ok = true;
    for(int i = 0; i < 3; i ++) {
        ok &= (a[i] == p || a[i] == q);
    }

    cout << (ok ? "YES" : "NO") << '\n';
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