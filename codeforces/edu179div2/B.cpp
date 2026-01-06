#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const i64 inf = 1e18;
#define int long long

// 猜结论

void solve() {
	vector<int> a(11);
    a[1] = 1, a[2] = 2;
    for(int i = 3; i <= 10; i ++) {
        a[i] = a[i - 1] + a[i - 2];
    }
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i ++) {
        int x, y, z;
        cin >> x >> y >> z;
        if(min({x, y, z}) >= a[n] && max({x, y, z}) >= a[n] + a[n - 1]) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;

    while(t --) {
        solve();
    }
    return 0;
}