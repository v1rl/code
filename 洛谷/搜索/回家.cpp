#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int N = 110;
int a[N][N];
typedef pair<int, int> PII;
int st[N][N];
int step[N][N];
int min_step[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    int n, m;
    cin >> n >> m;
    PII stt, edd;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++)
        {
            cin >> a[i][j];
            if(a[i][j] == 2) stt = {i, j};
            else if(a[i][j] == 3) edd = {i, j};
        }

    queue<PII> q;
    q.push(stt);
    st[stt.first][stt.second] = 6;
    step[stt.first][stt.second] = 0;
    while(q.size())
    {
        auto [x, y] = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(a[nx][ny] == 0) continue;

            int t = st[x][y] - 1;
            if(t == 0) continue;
            if(t <= st[nx][ny]) continue;
            st[nx][ny] = t;

            if(a[nx][ny] == 4) st[nx][ny] = 6;

            if(!step[nx][ny]) min_step[nx][ny] = step[nx][ny] = step[x][y] + 1;
            else step[nx][ny] = step[x][y] + 1;
            q.push({nx, ny});
        }
    }

       // for(int i = 1; i <= n; i ++)
       // {
       //  for(int j = 1; j <= m; j ++)
       //  {
       //      cout << min_step[i][j] << ' ';
       //  }
       //  cout << '\n';
       // }
 

    if(min_step[edd.first][edd.second]) cout << min_step[edd.first][edd.second];
    else cout << -1;
}