#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

const i64 inf = 1e18;

void solve() {
    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        a[i] = {y, x};
    }
    sort(a.begin(), a.end(), greater());
    i64 ans = 0;
    i64 cnt = 0;
    for(auto [y, x] : a) {
        ans += x - y * cnt;
        cnt ++;
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