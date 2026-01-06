#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    int mx = 0;
    int ans = 0;
    for(int i = 1; i < n; i ++) {
        int t = min(abs(a[i] - a[i - 1]), 8 - abs(a[i] - a[i - 1]));
        mx = max(mx, t);
        ans += t;
    }

    ans -= max(0, mx - min(abs(a[n - 1] - a[0]), 8 - abs(a[n - 1] - a[0])));
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
