#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define int long long

void solve() {
    int n, k, w;
    cin >> n >> k >> w;
    vector<array<int, 2>> a(n + 1);
    vector<int> b(n + 1);
    for(int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        a[i] = {x - w * (i - 1), i};
        b[i] = x;
    } 
    int ans = 0;
    vector<int> st(n + 1);

    sort(a.begin() + 1, a.end(), greater());
    for(int i = 1; i <= k; i ++) {
        // ans += a[i][0];
        st[a[i][1]] = true;
    }

    int pos = 1;
    for(int i = 1; i <= n; i ++) {
        if(st[i]) {
            ans += b[i] - (i - pos) * w;
            pos ++;
        }
    }

    cout << ans << '\n';

}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t --)
    {
        solve();
    }
}