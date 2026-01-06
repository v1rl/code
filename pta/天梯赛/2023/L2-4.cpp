#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector g(n + 1, vector(m + 1, '0'));
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            cin >> g[i][j];


    vector st(n + 1, vector(m + 1, false));
    int res1 = 0, res2 = 0;

    auto bfs = [&](int sx, int sy, bool &f)
    {
        queue<array<int, 2>> q;
        q.push({sx, sy});
        st[sx][sy] = true;
        while(q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            if(g[x][y] != '1') f = true;
            for(int i = 0; i < 4; i ++)
            {
                int nx = x + dx[i], ny = y + dy[i];
                if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
                if(g[nx][ny] == '0') continue;
                if(st[nx][ny]) continue;

                st[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    };

    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            if(!st[i][j] && g[i][j] != '0')
            {
                bool f = false;
                bfs(i, j, f);
                res1 ++;
                if(f) res2 ++;
            }
        }
    cout << res1 << ' ' << res2 << '\n';
}