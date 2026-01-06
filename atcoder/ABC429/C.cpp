#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

/*

*/

void solve() {
    int n;
    cin >> n;
    vector<int> st(n + 1);
    for(int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        st[x] ++;
    }

    i64 ans = 0;
    for(int i = 1; i <= n; i ++) {
        if(st[i] >= 2) {
            ans += 1ll * st[i] * (st[i] - 1) / 2 * (n - st[i]);
        }
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
