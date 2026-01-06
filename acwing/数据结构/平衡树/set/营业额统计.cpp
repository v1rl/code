#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 1e9;

void solve()
{
    set<int> S;
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i ++)
    {
        int x;
        cin >> x;
        if(i == 1) ans += x;
        else
        {
            int res = inf;
            auto pos = S.lower_bound(x);
            if(pos != S.end()) res = min(res, *pos - x);
            if(pos != S.begin()) res = min(res, x - *--pos);
            ans += res;
        }
        S.insert(x);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    t = 1;
    while(t --)
    {
        solve();
    }
}