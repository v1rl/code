#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];

    auto check = [&](int mid)
    {
        i64 res = mid;
        int d = 0;
        for(int i = 1; i <= n; i ++)
        {
            if(res > a[i] + d)
            {
                d = (a[i] + 1) / 2;
                res += a[i] / 2;
            }
            else return false;
        }
        return true;
    };

    int l = 1, r = 2e9;
    while(l < r)
    {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }

    cout << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    freopen("1.in", "r", stdin);
//    freopen("1.out", "w", stdout);
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
    return 0;
}
