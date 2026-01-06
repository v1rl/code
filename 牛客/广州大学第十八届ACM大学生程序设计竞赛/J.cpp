#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using i128 = __int128;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(m + 1, 0));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> g[i][j];
    
    int ans = 0;
    for(int p = 30; p >= 0; p --)
    {
        vector st(n + 1, vector(m + 1, 0));
        int ch = ans | (1 << p);
        
        queue<array<int, 2>> q;
        if((g[1][1] & ch) != ch) continue;
        q.push({1, 1});
        st[1][1] = true;
        
        while(q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            
            for(int i = 0; i < 4; i ++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(st[nx][ny]) continue;
                if((g[nx][ny] & ch) != ch) continue;
                st[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        
        if(st[n][m]) ans |= (1 << p);           
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
    return 0;
}

