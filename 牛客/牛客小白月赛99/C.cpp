#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
typedef pair<int, int> PII;
const int N = 1010;
char g[N][N];
int st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    array<int, 2> stt, edd;
    for(int i = 1; i <= n; i ++) 
        for(int j = 1; j <= m; j ++)
        {
            cin >> g[i][j];
            if(g[i][j] == 'S') stt = {i, j};
            else if(g[i][j] == 'E') edd = {i, j};
        }

    auto bfs = [&](int a, int b, int id)
    {
        queue<PII> q;
        st[a][b] = id;
        q.push({a, b});
        while(q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            for(int i = 0; i < 4; i ++)
            {
                int wx = x + dx[i], wy = y + dy[i];
                if(wx < 1 || wx > n || wy < 1 || wy > m) continue;
                if(g[wx][wy] == '#') continue;
                if(st[wx][wy]) continue;
                st[wx][wy] = id;
                q.push({wx, wy});
            }
        }
    };

    bfs(stt[0], stt[1], 1);
    if(st[edd[0]][edd[1]] == 1)
    {
        cout << "YES";
        return 0;
    }
    bfs(edd[0], edd[1], 2);

    set<int> row;
    set<int> col;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
            if(st[i][j] == 1)
            {
                row.insert(i);
                col.insert(j);
            }
    bool f = false;
    for(auto i : row)
    {
        for(int j = 1; j <= m; j ++)
        {
            if(g[i][j] == '#')
            {
                for(int k = 0; k < 4; k ++)
                {
                    int wx = i + dx[k], wy = j + dy[k];
                    if(wx < 1 || wx > n || wy < 1 || wy > m) continue;
                    if(st[wx][wy] == 2) f = true;
                }
            }
        }
    }

    for(auto j : col)
    {
        for(int i = 1; i <= n; i ++)
        {
            if(g[i][j] == '#')
            {
                for(int k = 0; k < 4; k ++)
                {
                    int wx = i + dx[k], wy = j + dy[k];
                    if(wx < 1 || wx > n || wy < 1 || wy > m) continue;
                    if(st[wx][wy] == 2) f = true;
                }
            }            
        }
    }
    if(f) cout << "YES" << '\n';
    else cout << "NO" << '\n';
    return 0;
}