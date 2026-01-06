#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
const double eps = 1e-6;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> d(n + 1);
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i ++)
    {
        cin >> w[i];
    }
    if(n == 1)
    {
        cout << 1 << '\n';
        return;
    }
    for(int i = 1; i <= m; i ++)
    {
        int x, y;
        cin >> x >> y;
        d[x] ++;
        d[y] ++;
    }
    // for(int i = 1; i <= n; i ++)
    // {
    //     cout << i << ' ' << d[i] << '\n';
    // }
    vector<int> a, b;
    for(int i = 1; i <= n; i ++)
    {
        if(d[i] != 1) a.emplace_back(w[i]);
        else b.emplace_back(w[i]);
    }
    int mx1 = 0;
    for(auto x : a)
    {
        mx1 = max(mx1, x);
    }
    int mx = 0, cmx = 0;
    for(auto x : b)
    {
        if(x > mx)
        {
            cmx = mx;
            mx = x;
        }
        else if(x > cmx)
        {
            cmx = x;
        }
    }
    cout << max(mx1, cmx) << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t = 1;
    // cin >> t;

    while(t --)
    {
        solve();
    }
    return 0;
}