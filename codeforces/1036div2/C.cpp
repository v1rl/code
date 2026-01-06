#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int ans = 1;
    for(int i = n; i >= 2; i --) {
        if(a[i - 1] > a[i]) {
            ans = max(ans, a[i - 1] / a[i]);
            a[i - 1] = a[i];
        }
    }
    cout << ans << '\n';
    cout << 255780 / 73080 << '\n';
    cout << gcd(255780, 73080) << '\n';

}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    cin >> t;
    while(t --)
    {
        solve();
    }
}