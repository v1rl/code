#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
const int inf = 2e9;

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> pmax(n + 1), pmin(n + 1);
    vector<int> smax(n + 2), smin(n + 2);
    vector<int> a(n + 1);
    pmin[0] = inf, smin[n + 1] = inf;
    for(int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        pmax[i] = max(pmax[i - 1], a[i]);
        pmin[i] = min(pmin[i - 1], a[i]);
    }
    for(int i = n; i; i --)
    {
        smax[i] = max(smax[i + 1], a[i]);
        smin[i] = min(smin[i + 1], a[i]);
    }

    vector<int> stk;
    vector<int> lc(n + 1), rc(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        while(!stk.empty() && a[stk.back()] < a[i])
        {
            int x = stk.back();
            rc[x] = lc[i];
            lc[i] = x;
            stk.pop_back();
        }
        stk.push_back(i);
    }

    while(stk.size() > 1)
    {
        int x = stk.back();
        stk.pop_back();
        rc[stk.back()] = x;
    }

    int ans = inf;
    auto dfs = [&](auto &&self, int x, int l, int r)->int
    {
        if(!x)
        {
            return inf;
        }
        int mn = min({self(self, lc[x], l, x - 1), self(self, rc[x], x + 1, r), a[x]});
        cout << l << ' ' << x << ' ' << r << '\n';
        int cmn = min({mn * 2, pmin[l - 1], smin[r + 1]});
        int cmx = max({a[x] * 2, pmax[l - 1], smax[r + 1]});
        ans = min(ans, cmx - cmn);
        return mn;
    };


    dfs(dfs, stk[0], 1, n);
    cout << ans << '\n';
}