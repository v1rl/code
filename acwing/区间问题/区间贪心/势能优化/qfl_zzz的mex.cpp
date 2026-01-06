#include <bits/stdc++.h>
using namespace std; 
using i64 = long long;
typedef pair<int, int> PII;
const int inf = 2e9;

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    
    int m = sqrt(x * 2) + 5;
    vector<queue<int>> q(m + 1);
    i64 sum = 0, ans = 0;
    for(int l = 1, r = 1; l <= n; l ++)
    {
        while(l == r || (r <= n && sum + a[r] <= x))
        {
            sum += a[r];
            if(a[r] <= m) q[a[r]].push(r);
            r ++;
        }
        
        int last = l;
        for(int i = 0; i <= m; i ++)
        {
            if(q[i].size() == 0)
            {
                if(last < r) ans += 1ll * (r - last) * i;
                break;
            }
            int net = q[i].front();
            if(net > last)
            {
                ans += 1ll * (net - last) * i;
                last = net;
            }
        }
        
        if(a[l] <= m) q[a[l]].pop();
        sum -= a[l];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while(t --)
    {
        solve();
    }
}