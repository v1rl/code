#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;

/*
*/

int n, x, y;

void solve() {
    cin >> n >> x >> y;
    vector<int> a(n);

    int mx = -1, pos = -1;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        if(a[i] / x * (x - y) + a[i] % x > mx) {
            mx = a[i] / x * (x - y) + a[i] % x;
            pos = i;
        }
    }

    i64 ans = 0;
    for(int i = 0; i < n; i ++) {
        if(i == pos) {
            ans += a[i];
        } else {
            ans += a[i] / x * y;
        }
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