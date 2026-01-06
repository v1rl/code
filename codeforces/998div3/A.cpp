#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve()
{
    vector<int> a(6);
    cin >> a[1] >> a[2] >> a[4] >> a[5];
    int ans = 0, res = 0;
    a[3] = a[1] + a[2];
    for(int i = 3; i <= 5; i ++)
        if(a[i] == a[i - 2] + a[i - 1])
            res ++;

    ans = res;

    res = 0;
    a[3] = a[5] - a[4];
    for(int i = 3; i <= 5; i ++)
        if(a[i] == a[i - 2] + a[i - 1])
            res ++;

    ans = max(ans, res);
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    cin >> t;
    while(t --)
    {
        solve();
    }
}