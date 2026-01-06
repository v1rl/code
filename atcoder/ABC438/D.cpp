#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*
后缀区间最大值

*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }    
    for(int i = 1; i <= n; i ++) {
        cin >> b[i];
    }    
    for(int i = 1; i <= n; i ++) {
        cin >> c[i];
    }    
    vector<i64> preb(n + 1), prea(n + 1), sufc(n + 2);
    for(int i = 1; i <= n; i ++) {
        prea[i] += prea[i - 1] + a[i];
        preb[i] += preb[i - 1] + b[i];
    }
    for(int i = n; i >= 1; i --) {
        sufc[i] += sufc[i + 1] + c[i];
    }

    vector<i64> mx(n + 1, 0);
    for(int i = n - 1; i >= 1; i --) {
        mx[i] = max(mx[i + 1], preb[i] + sufc[i + 1]);
    }

    i64 ans = 0;
    for(int i = 1; i <= n - 2; i ++) {
        ans = max(ans, prea[i] + mx[i + 1] - preb[i]);
    }
    cout << ans << '\n';
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
