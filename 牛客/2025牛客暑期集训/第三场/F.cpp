#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int ans = n % (a + b);
    if(n < a) {
        cout << "Sayonara" << '\n';
        return;
    }
    if(ans >= a) {
        ans -= a;
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}